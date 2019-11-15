# Class4 -- CNN简介

## 访谈

CNN可以用来对图像、语音等进行处理。

CNN非常实用，它的优势在于图片上任何位置的信息都可以灵活捕捉到。

*卷积是指向图像应用滤波器(核)的过程，最大池化是指通过下采样减低图像大小的过程。*

*CNN即卷积神经网络，即至少有一个卷积层的网络。典型的CNN还包括其他类型的层级，例如池化层和密集层。*

CNN的优势在于它可以从图像的各个区域中去学习特征，这样一来，需要的preprocess就会更少。它的灵感来自于大脑皮层中的神经元对图像的处理方式（也是分区域感知）

A ConvNet is able to **successfully capture the Spatial and Temporal dependencies** in an image through the application of relevant filters. 

卷积的优势在于可以捕捉图像中的空间和?信息。



# 卷积 Convolution

## 卷积 Convolution

> 核/滤波器：小于输入的矩阵，用于将输入变成多个小区域。

灰度图中的0代表黑色，255代表白色，我们需要将像素标准化为0~1的值。

卷积的基本思想是创新一个新的Matrix，称为 Kernel。卷积的过程就用这个Kernal扫描图像的各个区域。

输入是**Pixel Values**（原始图像），另外有**Kernel**（卷积核），卷积层的输出是**Convoluted Image**（卷积后的图像）。

卷积的具体计算过程是：目标位置(center of the kernel)的值为对应区域Kernel各位置和原图各位置的乘积和。

边缘像素的特殊处理：(1)直接忽略，但是会丢失信息，因为卷积图像比原始图像小得多；（2）零填充 zero padding，不会丢失信息了。

卷积也是一个层。

问题：核是如何构造的呢？

## 最大池化 Max pooling

> 池化有多种类型，比如最大池化、平均池化。最大池化是最常见的池化类型。

通过summarize regions对图像进行区域总结来减小图像大小。

需要两个参数：grid（网格），stride（步长）

取网格中的最大元素。网格移动步长长度。

这样之后我们就是down-sampled the original image。

## Colab

```python
model = tf.keras.Sequential([
    tf.keras.layers.Conv2D(32, (3,3), padding='same', activation=tf.nn.relu,
                           input_shape=(28, 28, 1)), #这一层后会有32个图片（称为channel)，padding=same代表使用填充，valid padding代表忽略吗？
    tf.keras.layers.MaxPooling2D((2, 2), strides=2),
    tf.keras.layers.Conv2D(64, (3,3), padding='same', activation=tf.nn.relu),
    tf.keras.layers.MaxPooling2D((2, 2), strides=2),
    tf.keras.layers.Flatten(), #将上一层的所有结果映射成一个1维的向量
    tf.keras.layers.Dense(128, activation=tf.nn.relu),
    tf.keras.layers.Dense(10,  activation=tf.nn.softmax) #和之前一样，都要加这两层
])
```

Flatten 之前的层叫 Feature Learning, Flatten及之后的层叫Classification

## 扩展

如果图像有多个channels（比如RGB），那么kernel也会有相同的深度。每一层分别去计算，然后最后加和。

卷积的作用是从图片中抽取一些高级的特征，比如边缘。

第一层的卷积层通常是抽取一些低级的特征，比如边缘、颜色、梯度取向

更高层的卷机层通常会对图片的理解更深。

池化层是用来缩减特征的空间的，这样就可以节省后续的计算能力。

另外，它也可以用来抽取dominant features(rotational and positional invariant)， 这些是什么特征？？

池化层通常有两种，最大池化层和平均池化层。最大池化层还有一个作用是降低噪声。因此一般我们说最大池化层的效果要好得多。

一个卷积层和一个池化层构成了卷积神经网络的其中一层。



在用于分类的FC Layer中，经过多个epoch的迭代，最终可以区分什么特征是high-level的，什么特征是Low-level的。

CNN已经有一些广泛应用的变体：LeNet, ResNet, AlexNet, VGGNet, GoogLeNet, ZFNet	

