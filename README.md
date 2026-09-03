# 2:4:2 Neural Network

C++ implementation of a **2:4:2 feedforward neural network** trained from scratch using batch backpropagation to learn two output patterns simultaneously.

## Method

* **Architecture:** 2:4:2
* **Hidden activation:** Sigmoid function
* **Output activation:** Linear function
* **Initial weights:** Manually initialized
* **Initial biases:** Manually initialized
* **Learning rate:** \(n=0.5\)
* **Learning rule:** Batch backpropagation
* **Loss function:** Sum of Squared Errors (SSE)
* **Epochs:** 1500

For each training sample, the hidden layer computes:

```math
a_j=w_{1j}x_1+w_{2j}x_2+b_j
```

```math
z_j=\frac{1}{1+e^{-a_j}}
```

The two linear outputs are:

```math
\hat{y}_1=v_{1a}z_1+v_{2a}z_2+v_{3a}z_3+v_{4a}z_4+b_a
```

```math
\hat{y}_2=v_{1b}z_1+v_{2b}z_2+v_{3b}z_3+v_{4b}z_4+b_b
```

The errors are:

```math
e_1=t_1-\hat{y}_1
```

```math
e_2=t_2-\hat{y}_2
```

SSE is calculated as:

```math
SSE=\sum_{i=1}^{N}(e_{1i}^2+e_{2i}^2)
```

Gradients from all four training samples are accumulated and averaged before updating the weights and biases.

## Dataset

| \(x_1\) | \(x_2\) | Target 1 | Target 2 |
| ------- | ------- | -------- | -------- |
| 0       | 0       | 0        | 0        |
| 0       | 1       | 0        | 1        |
| 1       | 0       | 0        | 1        |
| 1       | 1       | 1        | 1        |

## Results

The network is trained for **1500 epochs** using batch backpropagation.

The program reports the **SSE after each epoch** and the final updated weights.

The final outputs are produced using the trained parameters.

## Technologies

* C++
* STL `vector`
* Sigmoid activation
* Batch backpropagation
* Sum of Squared Errors (SSE)

