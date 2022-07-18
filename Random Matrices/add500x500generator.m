% Random Matrix Generator
% author: Mukund Ramakrishnan
% This program will generate two random matrices to be added, which will
% have dimensions 500x500 and have element values between 1 and 100,
% distributed uniformly.



fileID = fopen('add500x500.txt','w');

    array1 = randi(100,500,500);
    fmt=[repmat(' %1.0f',1,numel(array))];
    fprintf(fileID,fmt,array1);
    
    fprintf(fileID, '\n');
    
    array2 = randi(100,500,500);
    fmt=[repmat(' %1.0f',1,numel(array))];
    fprintf(fileID,fmt,array2);
    

fclose(fileID);