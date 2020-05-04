function [m]=load_map(filename)
    m=read(filename,-1,2);
    m=m';
endfunction

   
