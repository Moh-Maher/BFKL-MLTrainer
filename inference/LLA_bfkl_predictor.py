# Prepare new feature values for prediction
import pandas as pd
import joblib 
import numpy as np

# Load the trained model from the file
loaded_model = joblib.load('model_training/LLA_trained_model.joblib')



# Assuming you have already trained and saved the Random Forest model (rf_model)

# Create a range of "nu" values from -100 to 100
nu_values = np.arange(-100, 101)

# Create a DataFrame with "nu" values and other constant features
new_feature_values = pd.DataFrame({
    'n': [0] * len(nu_values),
    'nu': nu_values,
    'Y': [5.5] * len(nu_values),
    'MuR': [30.0] * len(nu_values),
})

# Predict scattering amplitudes for the new feature values using the Random Forest model
predicted_amplitudes = loaded_model.predict(new_feature_values)

# Create a new DataFrame with 'nu' and 'predicted_amplitudes' columns
output_table = pd.DataFrame({'#nu': nu_values, 'Predicted Scattering Amplitudes': predicted_amplitudes})

# Print the output table
print(output_table)

# Save the output table to a file named "output.dat" (tab-separated)
output_table.to_csv('data/output_predictions/LLA_output.dat', sep='\t', index=False, header=False)
 
