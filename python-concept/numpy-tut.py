"""this is the tutorial for numpy array in python"""
import numpy as np
import sys
def datatype() :
    x=np.array([1,2,3])
    y=np.array([4,5,6])

    print(x)
    print(y)

    x=x+x
    print(x)

    y=y-x
    print(y)

    print(x[0])

    #now lets get introduces to different data types numpy can handle 

    x=np.float32(1.0)
    print(x)

    x=np.int_([1,2,4])
    print(x)

    x=np.arange(100,dtype=np.int8)
    print(x)
    """
    [ 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
     25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49
     50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74
     75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99]"""

    x=np.array([1,2,3],dtype='i')       #integer32
    print(x)
    x=x.astype(float)                   #float
    print(x)
    x=np.int8(x)                        #integer8
    print(x)
    print(x.dtype)                      #type of the numpy
    #a=np.issubdtype(x, int)
    #a=np.issubdtype(x, float)
pass


def python_array_like_objects_to_numpy_array() :
    x=np.array([1,2,2,32,23])
    y=np.array([[1,3,3,32,32,32],[23,324,5],['zcx','s','sdsd']])
    print(np.mean(x[:]))
    #12.0
    x=np.zeros((2,3))
    #[[ 0.  0.  0.] [ 0.  0.  0.]]
    x=np.arange(10)
    #[0 1 2 3 4 5 6 7 8 9]
    x=np.arange(2,10,dtype=np.float)
    #[ 2.  3.  4.  5.  6.  7.  8.  9.]
    x=np.arange(2,3,0.1)
    #[ 2.   2.1  2.2  2.3  2.4  2.5  2.6  2.7  2.8  2.9]
    x=np.linspace(1.,4.,6)
    #[ 1.   1.6  2.2  2.8  3.4  4. ]
    x=np.indices((3,3))
    print(x)
    """
        [[[0 0 0]
          [1 1 1]
          [2 2 2]]

         [[0 1 2]
          [0 1 2]
          [0 1 2]]]
    """
    s=tuple('abc')
    #('a', 'b', 'c')

def edx1():
    # Calculate the BMI: bmi
    height=[]
    weight=[]
    np_height_m = np.array(height) * 0.0254
    np_weight_kg = np.array(weight) * 0.453592
    bmi = np_weight_kg / np_height_m ** 2

    # Create the light array
    light=np.array([x<21 for x in bmi ])

    # Print out light

    print(light)
    # Print out BMIs of all baseball players whose BMI is below 21
    print(bmi[light])#<-----notice the use
pass

def edx2() :
    # Create baseball, a list of lists
    baseball = [[180, 78.4],
                [215, 102.7],
                [210, 98.5],
                [188, 75.2]]

    # Import numpy
    import numpy as np

    # Create a 2D Numpy array from baseball: np_baseball
    np_baseball=np.array(baseball)

    # Print out the type of np_baseball
    print(type(np_baseball))

    # Print out the shape of np_baseball
    print(np_baseball.shape)
pass

def edx3() :
    # baseball is available as a regular list of lists

    # Import numpy package
    import numpy as np

    # Create np_baseball (2 cols)
    np_baseball = np.array(baseball)
    # Print out the 50th row of np_baseball

    print(np_baseball[49,:])
    # Select the entire second column of np_baseball: np_weight
    np_weight=np_baseball[:,1]

    # Print out height of 124th player
    print(np_baseball[123][0])
pass

def edx4() :
    import numpy as np

    # Print mean height (first column)
    avg = np.mean(np_baseball[:,0])
    print("Average: " + str(avg))

    # Print median height. Replace 'None'
    med = np.median(np_baseball[:,0])
    print("Median: " + str(med))

    # Print out the standard deviation on height. Replace 'None'
    stddev =np.std(np_baseball[:,0])
    print("Standard Deviation: " + str(stddev))

    # Print out correlation between first and second column. Replace 'None'
    corr = np.corrcoef(np_baseball[:,0],np_baseball[:,1])
    print("Correlation: " + str(corr))
pass
def main() :
    python_array_like_objects_to_numpy_array()
pass

if __name__== main() :
    sys.exit(0)
pass