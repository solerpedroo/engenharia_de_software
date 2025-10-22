for i=1:3
    for j=1:4
        if i<j then A(i,j) = j+1
        elseif i>j then A(i,j) = i+j
        elseif i==j then A(i,j) = 2*i
        end
    end
end

printf("A=\n")
disp(A)

printf("Soma dos elementos da 2 linha=%f\n",sum(A(2,:)))
printf("Soma dos elementos da 3 coluna=%f\n",sum(A(:,3)))
