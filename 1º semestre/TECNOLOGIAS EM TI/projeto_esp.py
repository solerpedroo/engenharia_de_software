import network
from machine import Pin
from time import sleep

rede = network.WLAN(network.STA_IF)
rede.active(True)

try:
    import usocket as socket
except:
    import socket

rede.connect("Wokwi-GUEST", "")
while not rede.isconnected():
    print(".", end="")
    sleep(0.5)

print("\nConectado! IP:", rede.ifconfig())

led_vermelho = Pin(0, Pin.OUT)
led_azul = Pin(4, Pin.OUT)
led_verde = Pin(2, Pin.OUT)

def web_page():
    html = """ 
     <html>
      <head>
      </head>
      <body>
        <h1> PEDRO SOLER AULA TEC TI</h1>
        </body>
     </html>
     """

    return html

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('', 80))
s.listen(5)
print("Aguardando conexões...")

try:
    while True:
        conn, addr = s.accept()
        print('Conectado de:', addr)
        request = conn.recv(1024)
        request = str(request)
        print("Requisição:", request)

        if "/on_vermelho" in request:
            led_vermelho.value(1)
        if "/off_vermelho" in request:
            led_vermelho.value(0)

        if "/on_azul" in request:
            led_azul.value(1)
        if "/off_azul" in request:
            led_azul.value(0)

        if "/on_verde" in request:
            led_verde.value(1)
        if "/off_verde" in request:
            led_verde.value(0)

        if "/on_todos" in request:
            led_vermelho.value(1)
            led_azul.value(1)
            led_verde.value(1)

        if "/off_todos" in request:
            led_vermelho.value(0)
            led_azul.value(0)
            led_verde.value(0)

        conn.send("HTTP/1.1 200 OK\r\n")
        conn.send("Content-Type: text/html\r\n")
        conn.send("Connection: close\r\n\r\n")
        conn.sendall(web_page())
        conn.close()

except KeyboardInterrupt:
    print("\nServidor encerrado pelo usuário.")
    s.close()