function [eigens,eigensT] = readComplexFile(filename, dataLines)
%% Input handling

% If dataLines is not specified, define defaults
if nargin < 2
    dataLines = [1, Inf];
end

%% Set up the Import Options and import the data
opts = delimitedTextImportOptions("NumVariables", 2);

% Specify range and delimiter
opts.DataLines = dataLines;
opts.Delimiter = ",";

% Specify column names and types
opts.VariableNames = ["real", "img"];
opts.VariableTypes = ["double", "double"];

% Specify file level properties
opts.ExtraColumnsRule = "ignore";
opts.EmptyLineRule = "read";

% Specify variable properties
opts = setvaropts(opts, ["real", "img"], "TrimNonNumeric", true);
opts = setvaropts(opts, ["real", "img"], "ThousandsSeparator", ",");

% Import the data
eigensF = readtable(filename, opts);

%% Convert to output type
eigensF = table2array(eigensF);
len = size(eigensF,1);
split = (len-1)/2;
eigens = toEigenVals(eigensF(1:split,:));
eigensT = toEigenVals(eigensF(split+2:len,:));
end


function eigVals = toEigenVals(eigarr)
    eigVals=eigarr(:,1)+eigarr(:,2)*1i;
end