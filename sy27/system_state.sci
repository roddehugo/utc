function [_x]=f(x, u, v, L)
    //x=(y,theta)
    _x(1) = v * cos(u) * sin(x(2));
    _x(2) = v * sin(u) / L;
endfunction

function [z]=g(x)
    z = x(1);
endfunction
