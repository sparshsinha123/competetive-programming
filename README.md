# time-series-outlier-detection

A python script which contains functions which perform time series decomposition (using STL / Classical decomposition) and returns the outliers in the series along with severity scores for the outliers

# Usage with default parameters : ./time_series_analysis.py <input_file> -o <output_file>

# OPTIONS
    -i <input_file>
        Input file from which to read input
    -o <output_file>")
        Output the outliers to the output file
    --verbose=1
        Prints all important values and data. May be slow for large data sets
    --index_col=<index_col>
        Column which is to be taken as the date time index
    --method=<method_name>
        Method to be used for decomposition. Values accepted : STL or CLASSICAL
    --seasonality_stl=<seasonality>
        The seasonality of the time series which is to be determined if STL is used
    --robust=<boolean_value>
        Specifying the nature of STL decomposition. If not provided the default value is 1. If 0 provided 
        robust flag is set to false. Robustness means the STL algorithm will be robust to outliers
    --seasonality_cl=<seasonality>
        The seasonality for the classical decomposition
    --model_cl=<type_of_model>
        The type of model for the classical decomposition. Values accepted: 'additive or multiplicative' 
    --outlier_detection_algorithm=<algorithm>")
        The algorithm to use for outlier detection. Currently only one value accepted- GLOBAL_IQR
    --K=<numeric_or_float_value>
        The higher the K , the more linient the model is to outliers. Defaults to 1.5
    --help
        Prints the documentation 

   # Example usage:
    ./time_series_analysis.py -i input.csv -o output.csv --verbose=1 --index_col='Date' --method=CLASSICAL --seasonality_stl=7 --robust=1") 
