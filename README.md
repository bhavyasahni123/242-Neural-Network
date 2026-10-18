# 2–4–2 Neural Network in C++

A feedforward neural network implemented from scratch in C++ to learn two output patterns simultaneously. The network uses a single hidden layer, sigmoid activation, linear output neurons, and batch backpropagation.

This project explores how a multi-output neural network processes inputs, calculates prediction errors, accumulates gradients, and updates its parameters during training.

## Network Architecture

The network follows a **2–4–2 architecture**:

- **Input layer:** 2 neurons
- **Hidden layer:** 4 neurons with sigmoid activation
- **Output layer:** 2 neurons with linear activation

The network maps two input values, \(x_1\) and \(x_2\), to two predicted outputs, \(\hat{y}_1\) and \(\hat{y}_2\).

## Training Configuration

| Parameter | Configuration |
|---|---|
| Architecture | 2–4–2 |
| Hidden activation | Sigmoid |
| Output activation | Linear |
| Initial weights | Manually initialized |
| Initial biases | Manually initialized |
| Learning rate | 0.5 |
| Learning algorithm | Batch backpropagation |
| Loss function | Sum of Squared Errors (SSE) |
| Training samples | 4 |
| Epochs | 1,500 |

## Forward Propagation

Forward propagation calculates the network's predictions from the input values and the current weights and biases.

### 1. Hidden Layer

Each hidden neuron \(j\) calculates a weighted sum of the two inputs:

$$
a_j=w_{1j}x_1+w_{2j}x_2+b_j
$$

The sigmoid activation function transforms this weighted sum:

$$
z_j=\sigma(a_j)=\frac{1}{1+e^{-a_j}}
$$

where \(z_j\) is the output of hidden neuron \(j\).

### 2. Output Layer

The network has two output neurons, each using a linear activation function.

The first predicted output is:

$$
\hat{y}_1=\sum_{j=1}^{4}v_{ja}z_j+b_a
$$

The second predicted output is:

$$
\hat{y}_2=\sum_{j=1}^{4}v_{jb}z_j+b_b
$$

Here, \(v_{ja}\) and \(v_{jb}\) are the weights connecting hidden neuron \(j\) to the first and second output neurons, respectively. The terms \(b_a\) and \(b_b\) are the output biases.

Using linear output neurons allows the predictions to take values outside the interval \([0,1]\), even though the hidden-layer activations are bounded by the sigmoid function.

## Dataset

The network is trained on four input-output pairs.

| \(x_1\) | \(x_2\) | Target \(t_1\) | Target \(t_2\) |
|---:|---:|---:|---:|
| 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 |
| 1 | 1 | 1 | 1 |

Each sample contains two inputs and two target outputs. The network learns both output mappings simultaneously using the same hidden-layer representation.

## Error Calculation

For each training sample, the prediction errors are calculated as the difference between the target and predicted outputs:

$$
e_1=t_1-\hat{y}_1
$$

$$
e_2=t_2-\hat{y}_2
$$

The Sum of Squared Errors (SSE) across all \(N\) training samples is:

$$
\mathrm{SSE}=\sum_{i=1}^{N}
\left(e_{1i}^{2}+e_{2i}^{2}\right)
$$

In this project, the training dataset contains \(N=4\) samples.

SSE measures the total squared prediction error across both outputs and all training samples. A lower SSE indicates smaller squared errors on the training dataset.

## Batch Backpropagation

The network uses batch backpropagation to train its weights and biases.

The training process follows these steps:

1. Perform forward propagation for each training sample.
2. Calculate the errors for both output neurons.
3. Propagate the errors backward through the network.
4. Accumulate gradient contributions from all four training samples.
5. Average the accumulated gradients and update the weights and biases.
6. Repeat the process for 1,500 epochs.

The sigmoid derivative used when propagating gradients through the hidden layer is:

$$
\sigma'(a_j)=z_j(1-z_j)
$$

The hidden neurons share information with both output neurons through their outgoing weights. Consequently, the hidden-layer updates account for the contributions of both outputs.

**Batch learning** means that parameter updates are performed after the gradient contributions from the training samples have been accumulated, rather than updating the parameters separately after every sample.

## Results

The program trains the network for **1,500 epochs**.

During training, it reports:

- The SSE after each epoch.
- The final updated weights and biases.
- The final network outputs calculated using the trained parameters.

The four training samples are the data used to fit the network. Results on these samples alone do not establish generalization to unseen data.

No specific final SSE, accuracy percentage, or convergence threshold is claimed here because those values should be taken directly from the program's output.

## Technologies Used

- **C++** — Neural network implementation and training.
- **STL `vector`** — Storage and manipulation of data and network parameters.
- **Sigmoid activation** — Nonlinear hidden-layer transformation.
- **Backpropagation** — Gradient computation for network parameters.
- **Batch gradient descent** — Updating parameters using accumulated gradients.
- **Sum of Squared Errors** — Measuring the training error.

## Key Concepts Demonstrated

- Feedforward neural network architecture.
- Multi-output prediction.
- Forward propagation through hidden and output layers.
- Sigmoid activation and its derivative.
- Error calculation using SSE.
- Backpropagation through a shared hidden layer.
- Batch gradient accumulation and parameter updates.
- Training a neural network on a small, explicitly defined dataset.


## Conclusion

This project demonstrates the fundamentals of a multi-output feedforward neural network implemented from scratch in C++. With a 2–4–2 architecture, sigmoid hidden neurons, linear output neurons, and batch backpropagation, it provides a compact example of how neural networks learn multiple output mappings from a shared hidden representation.
