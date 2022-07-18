% Random Matrix Generator
% author: Mukund Ramakrishnan
% This program will generate two random matrices to be multiplied, which will
% have dimensions 500x1000 and 1000x500 and have element values between 1 and 100,
% distributed uniformly.

fileID = fopen('multiply500x1000.txt','w');

    array1 = randi(100,500,1000);
    fmt=[repmat(' %1.0f',1,numel(array))];
    fprintf(fileID,fmt,array1);
    
    fprintf(fileID, '\n');
    
    array2 = randi(100,1000,500);
    fmt=[repmat(' %1.0f',1,numel(array))];
    fprintf(fileID,fmt,array2);
    

fclose(fileID);