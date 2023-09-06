# BFKL-MLTrainer

**BFKL-MLTrainer** is a project that facilitates the use of machine learning models for the BFKL (Balitsky-Fadin-Kuraev-Lipatov) kernel. It provides a command-line interface (CLI) through the `main.cpp` file, allowing users to perform various tasks related to BFKL calculations, predictions, and model training.

## Table of Contents

- [Introduction](#bfkl-mltrainer)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
  - [Options](#options)
  - [Predictions](#predictions)
  - [Model Training](#model-training)
  - [Plotting](#plotting)
- [License](#license)

## Getting Started

### Prerequisites

Before you begin, ensure you have the following dependencies installed:

- C++ compiler (e.g., g++)
- Python 3.x
- Matplotlib (for plotting, install using `pip install matplotlib`)
- Required Python libraries specified in `requirements.txt`

### Installation

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/moh-maher/BFKL-MLTrainer.git
   ```

2. Navigate to the project directory:

   ```bash
   cd BFKL-MLTrainer
   ```

3. Install the required Python libraries using `pip`:

   ```bash
   pip install -r requirements.txt
   ```

## Usage

### Options

The `main.cpp` file provides a command-line interface with the following options:

- **1. Predict data**: Choose this option to make predictions using trained models.

- **2. Training data**: Select this option to train a new model or use preexisting data for training.

- **3. Plotting LLA/NLA predictions**: Use this option to create plots for LLA/NLA predictions.

### Predictions

If you choose option 1, you can further select:

- **LLA BFKL Predictions**: Run LLA BFKL prediction script (`inference/LLA_bfkl_predictor.py`).

- **NLA BFKL Predictions**: Run NLA BFKL prediction script (`inference/NLA_bfkl_predictor.py`).

### Model Training

If you choose option 2, you can:

- **New data**: Compile and run data generation code (`src/data_generator.cpp`) to create new data for model training.

- **Preexist data**: Choose between LLA or NLA model training scripts located in `model_training` directory (`model_training/LLA_bfkl_training.py` or `model_training/NLA_bfkl_training.py`).

### Plotting

If you choose option 3, you can create plots for LLA/NLA predictions by compiling and running the plotting code (`src/plotting.cpp`) with Python integration.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

This README file provides an overview of the project and how to use the `main.cpp` CLI for various tasks related to the BFKL-MLTrainer project. You can customize this README further to include specific details about your project's functionalities, examples of usage, and additional sections or information as needed.
