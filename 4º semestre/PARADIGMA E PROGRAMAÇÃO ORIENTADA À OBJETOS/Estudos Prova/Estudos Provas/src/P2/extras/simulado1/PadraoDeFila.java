package P2.extras.simulado1;

public interface PadraoDeFila<T> {
    void guardeItem(T item) throws Exception;
    T getItem() throws Exception;
    void removaItem() throws Exception;
}
