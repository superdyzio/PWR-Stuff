clear all;

RIGHT = 1;
DOWN = 2;
LEFT = 3;
UP = 4;

cols = 5;
rows = 5;

kierunek = RIGHT;

x = zeros(rows, cols);
y = 1;
w = 1;
k = 1;

for i = 1 : 25;
    x(w,k) = y;
    y = y+1;
    switch kierunek
        case RIGHT
            if k < cols && x(w, k+1) == 0
                k = k+1;
            else
                w = w+1;
                kierunek = DOWN;
            end;
        case DOWN
            if w < rows && x(w+1, k) == 0
                w = w+1;
            else
                k = k-1;
                kierunek = LEFT;
            end;
        case LEFT
            if k > 1 && x(w, k-1) == 0
                k = k-1;
            else
                w = w-1;
                kierunek = UP;
            end;    
        case UP
            if w > 1 && x(w-1, k) == 0
                w = w-1;
            else
                k = k+1;
                kierunek = RIGHT;
            end;
    end;
end;

x