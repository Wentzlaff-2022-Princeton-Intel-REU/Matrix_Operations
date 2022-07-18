% Random Matrix Generator
% author: Mukund Ramakrishnan
% This program will generate two random matrices to be multiplied, which will
% have dimensions 100x200 and 200x100 and have element values between 1 and 100,
% distributed uniformly.



fileID = fopen('multiply100x200.txt','w');

    array1 = randi(100,100,200);
    fmt=[repmat(' %1.0f',1,numel(array))];
    fprintf(fileID,fmt,array1);
    
    fprintf(fileID, '\n');
    
    array2 = randi(100,200,100);
    fmt=[repmat(' %1.0f',1,numel(array))];
    fprintf(fileID,fmt,array2);
    

fclose(fileID);