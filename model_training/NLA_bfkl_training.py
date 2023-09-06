import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error, r2_score
import joblib


# Now you can use the loaded_model for predictions

# Load the data from the CSV file
data = pd.read_csv('data/data_preparation/NLA_Kernel.csv')

# Separate the features (X) from the target variable (y)
X = data.drop('NLA_Kernel', axis=1)
y = data['NLA_Kernel']

# Split the data into training and testing sets (80% training, 20% testing)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create and train the Random Forest model
print("Training in progress ...")
rf_model = RandomForestRegressor(n_estimators=100, random_state=42)
rf_model.fit(X_train, y_train)

# Make predictions on the test data
y_pred_rf = rf_model.predict(X_test)

# Evaluate the Random Forest model
mse_rf = mean_squared_error(y_test, y_pred_rf)
r2_rf = r2_score(y_test, y_pred_rf)

print("Random Forest - Mean Squared Error:", mse_rf)
print("Random Forest - R-squared:", r2_rf)


# Save the trained model to a file
joblib.dump(rf_model, 'model_training/NLA_trained_model.joblib')
