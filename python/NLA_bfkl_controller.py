import sys
import pandas as pd
import joblib
import numpy as np

# Load the trained model from the file
loaded_model = joblib.load('model_training/NLA_trained_model.joblib')


# Parse command-line arguments
n = int(sys.argv[1])
nu_start = int(sys.argv[2])
nu_end = int(sys.argv[3])
Y = float(sys.argv[4])
MuR = float(sys.argv[5])

# Create a range of "nu" values
nu_values = np.arange(nu_start, nu_end + 1)

# Create a DataFrame with input values and "nu" values
new_feature_values = pd.DataFrame({
    'n': [n] * len(nu_values),
    'nu': nu_values,
    'Y': [Y] * len(nu_values),
    'MuR': [MuR] * len(nu_values),
})

# Predict scattering amplitudes for the new feature values using the Random Forest model
predicted_amplitudes = loaded_model.predict(new_feature_values)

# Create a new DataFrame with 'nu' and 'predicted_amplitudes' columns
output_table = pd.DataFrame({'#nu': nu_values, 'Predicted Scattering Amplitudes': predicted_amplitudes})

# Print the output table
print(output_table)

# Save the output table to a file named "output.dat" (tab-separated)
output_table.to_csv('data/output_predictions/NLA_output.dat', sep='\t', index=False,header=False)

