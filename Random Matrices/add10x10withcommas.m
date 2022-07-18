% Random Matrix Generator
% author: Mukund Ramakrishnan
% This program will generate two random matrices to be added, which will
% have dimensions 10x10 and have element values between 1 and 100,
% distributed uniformly.



fileID = fopen('add10x10withcommas.txt','w');

    array1 = randi(100,10,10);
    fmt=[repmat('%1.0f, ',1,numel(array))];
    fprintf(fileID,fmt,array1);
    
    fprintf(fileID, '\n');
    
    array2 = randi(100,10,10);
    fmt=[repmat('%1.0f, ',1,numel(array))];
    fprintf(fileID,fmt,array2);
    

fclose(fileID);