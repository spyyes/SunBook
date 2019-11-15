# Class3 -- 首个模型-Fashion MNIST

## Fashion MNIST 数据集

28*28的像素，有10个可能的类别

## 神经网络

> 扁平化、ReLU、Softmax、分类

```python
tf.keras.layers.Flatten(input_shape=(28,28,1))
tf.keras.layers.Dense(128, activation=tf.nn.relu)
tf.keras.layers.Dense(10, activation=tf.nn.softmax) 

```

### Flatten

**扁平化：**将二维图像转换为一维向量的过程

### Softmax

Softmax：一种函数，能够为每个潜在输出类别生成概率

每个分类问题最后都有一个Dense层（units=可能的类别数，activation=softmax）。每一个类别的输出就是它可能的概率分布。

### ReLU 修正线性单元

![1573795179542](C:\Users\spy\AppData\Roaming\Typora\typora-user-images\1573795179542.png)

ReLU可以用来增强米基层的效果。使得网络能够解决非线性问题。

它是一种激活函数。激活函数一般有ReLU\Sigmoid\双曲正切\ELU，但是ReLU是最常用的激活函数。

## Colab : Fashion MNIST

normalize是一个常用的技巧，可以将数值归一到0-1中，这是在机器学习中常用的手段。

区分epoch, step(好像没有什么用）, period（用于及时输出训练信息）

## 总结

上一节课的是regression problem，这一节课的是classification problem

## 拓展 ·regression problems

seaborn：一个画图的包

normalization：去除一些极端的值。方法有很多，比如根据平均值和方差来进行归一化。

在model.fit阶段可以指定validation set的大小

可以save 训练过程的history 结果

处理过拟合问题可以用early stopping：在结果没有改进的时候就停止训练，用validation的结果来指导何时停止，需要设置patience：

keras.earlystopping

 