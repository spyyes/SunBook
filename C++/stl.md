### 优先队列实现最小堆和最大堆

**优先输出大数据**

priority_queue<Type, Container, Functional>

Type为数据类型， Container为保存数据的容器，Functional为元素比较方式。

如果不写后两个参数，那么容器默认用的是vector，比较方式默认用operator<，也就是优先队列是大顶堆，队头元素最大。

**优先输出小数据**

```
priority_queue<int, vector<int>, greater<int> > p;
```

**插入删除**

```
push()
pop()
```

### qsort自定义排序

qsort的复杂度



```
int compare(const void * num1, const void * num2){
	
}
qsort(start, size, sizeof(item), compare);
```

### sprintf

```
sprintf(str, "%d", num);
```

### hashset

set和hashset的区别

```
hash_set<char>hset;
if(hset.find(ch) != hset.end()){
}
```



### 快速排序的复杂度

