# Class5 -- CNN新

## 访谈

解决过拟合问题通常有两种方式：

- Early Stopping：将数据集划分成训练集和验证集，进行交叉验证，如果发现效果不再有明显提升，就停止训练。
- 对参数进行约束，约束条件越强，就越可能避免过拟合。

## 处理不同尺寸

神经网络的输入必须是固定尺寸的。需要将所有的图片调整尺寸到相同的大小(resize)

## 处理颜色

Conv2D修改两个地方

## 卷积运算

kernel 的depth将是3，称为3Dfilter。最终的卷积结果是3层的卷积结果加和。

实际中通常会使用多个3D Filter(就是Con2D的多个输出图像)，那么最后卷积出来的结果就是一个(width, height, depth=units)的3D Convolutional Output。

```
Conv2D(filters, sizeofkernel)
```

CNN训练的过程中，核中的值是不断更新的。

## 对彩色图像进行最大池化运算

maxpooling改变长度和宽度，但是不改变深度。

## Colab

## Softmax & sigmoid

处理二分类问题时，有另外一种方式：

```python
# Plan1 
tf.keras.layers.Dense(512, activation='relu'),
# Plan2
tf.keras.layers.Dense(2, activation='softmax')
tf.keras.layers.Dense(1, activation='sigmoid')
model.compile(optimizer='adam', 
              loss='binary_crossentropy', #Watch this!
              metrics=['accuracy'])
```

## 利用验证集进行过拟合的处理

> 防过拟合技术1

通过验证集的loss来选择模型结构、或者决定应该在什么时候停止。

## 图像增强

> 增强CNN结果& 防过拟合技术2

我们需要一个无论狗在图像的哪个位置、多大、是否只有一半，都可以进行识别的CNN。如果有足够的数据，自然没有问题，但是现实中的数据往往是不足的。

因此，我们可以使用图像增强。

向原始图像进行旋转、翻转、随机缩放。将这些新转换得图像加入训练集中。

这样可以增强CNN的泛化能力。

## Dropout

> 防过拟合技术3

一部分神经元的权重很大，另一部分的神经元权重很小。

Dropout技术是将一些神经元关掉，使得另一些神经元发挥它们的作用。

每一轮关闭不同的一些神经元。

这样训练出的网络抵抗力会更强，因为一些神经元不工作的情况下仍然可以识别。

神经元的关闭具有随机性，有一些被关闭了不止一次，有一些没有被关闭过。

训练结果会在训练集上有所下降（因为使用了图像增强技术）、但是会在验证机上有所上升。

```python
tf.keras.dropout(0.5) #有50%的值会被置0
```

## Colab

rescale是将所有像素乘上一个放缩因子，即将所有的像素都放在0~1的取值中。

```python
model = tf.keras.models.Sequential([
  tf.keras.layers.Conv2D(32, (3,3), activation='relu', input_shape=(150, 150, 3)),
  tf.keras.layers.MaxPooling2D(2, 2),
  tf.keras.layers.Conv2D(64, (3,3), activation='relu'),
  tf.keras.layers.MaxPooling2D(2, 2),   
  tf.keras.layers.Conv2D(128, (3,3), activation='relu'),
  tf.keras.layers.MaxPooling2D(2, 2),  
  tf.keras.layers.Conv2D(128, (3,3), activation='relu'),
  tf.keras.layers.MaxPooling2D(2, 2), 

  tf.keras.layers.Dropout(0.5),
  tf.keras.layers.Flatten(),
  tf.keras.layers.Dense(512, activation='relu'),
  tf.keras.layers.Dense(2, activation='softmax') 
])
```

对比之前灰度图上的卷积：

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

