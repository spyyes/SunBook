class CArray{
private:
    int * array;
    int size;
public:
    void push_back(int i){
        if(array == NULL){
            array = new int[1];
            array[0] = i;
        }
        else{
            int * tmpArray = new int[size + 1];
            memcpy(tempArray, array, sizeof(int) * size);
            size++;
            delete[]array;
            array = tmpArray;
            array[size - 1] = i;             
        }
    }
    CArray & operator = (const CArray& c){
        if(array == c.array){ //防止a==a
            return *this;
        }
        else{
            if(array){
                delete[] array;
                array = new int[c.size + 1];
                size = c.size;
                memcpy(array, c.array, sizeof(int)*c.size);
            }else{
                array = new int[c.size + 1];
                size = c.size;
                memcpy(array, c.array, sizeof(int)*c.size);
            }
        }
    }
};