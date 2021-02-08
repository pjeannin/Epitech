mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x
    | x < 0 = True
    | otherwise = False

myAbs :: Int -> Int
myAbs x
    | x < 0 = x * (-1)
    | otherwise = x

myMin :: Int -> Int -> Int
myMin x y
    | x < y = x
    | otherwise = y

myMax :: Int -> Int -> Int
myMax x y
    | x > y = x
    | otherwise = y

myTuple :: a -> b -> (a, b)
myTuple x y = (x, y)

myTruple :: a -> b -> c -> (a, b, c)
myTruple x y z = (x, y, z)

myFst :: (a, b) -> a
myFst (x, y) = x

mySnd :: (a, b) -> b
mySnd (x, y) = y

mySwap :: (a, b) -> (b, a)
mySwap (x, y) = (y, x)

myHead :: [a] -> a
myHead [] = error "empty list"
myHead (x:_) = x

myTail :: [a] -> [a]
myTail [] = error "empty list"
myTail (x:xs) = xs

myLength :: [a] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs

myNth :: [a] -> Int -> a
myNth (x:xs) y
    | y < 0 = error "Index cannot be negative"
    | y >= myLength (x:xs) = error "Index out of range"
    | y == 0 = x
    | otherwise = myNth xs (y - 1)

myTake :: Int -> [a] -> [a]
myTake y (x:xs)
    | y >= myLength (x:xs) = x:xs
    | y < 0 = error "Index cannot be negative"
    | y == 0 = []
    | otherwise = x : myTake (y - 1) xs

myDrop :: Int -> [a] -> [a]
myDrop y (x:xs)
    | y >= myLength (x:xs) = []
    | y == 0 = x:xs
    | otherwise = myDrop (y - 1) xs

myAppend :: [a] -> [a] -> [a]
myAppend (x:xs) y = x : myAppend xs y
myAppend [] y = y

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]

myInit :: [a] -> [a]
myInit [] = error "The list is empty"
myInit [x] = []
myInit (x:xs) = x : myInit xs

myLast :: [a] -> a
myLast [] = error "The list is empty"
myLast [x] = x
myLast (x:xs) = myLast xs

myZip :: [a] -> [b] -> [(a, b)]
myZip [] (y:ys) = error "cannot use empty list"
myZip (x:xs) [] = error "cannot use empty list"
myZip [x] (y:ys) = [(x, y)]
myZip (x:xs) [y] = [(x, y)]
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys

myMap :: (a -> b) -> [a] -> [b]
myMap f xs = [f x | x <- xs]

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip x = (myMap myFst x, myMap mySnd x)

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter f (x:xs)
    | f x = x : myFilter f xs
    | otherwise = myFilter f xs

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl f y [] = y
myFoldl f y (x:xs) = myFoldl f (f y x) xs

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr f y [] = y
myFoldr f y (x:xs) = f x (myFoldr f y xs)

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])
myPartition f (x:xs)
    | f x       = (x:accepted, rejected)
    | otherwise = (accepted, x:rejected)
    where (accepted, rejected) = myPartition f xs