--
-- EPITECH PROJECT, 2021
-- B-FUN-300-LYN-3-1-funPoolDay1-clement.fleur
-- File description:
-- My
--


-- step1
mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x = case (myIsNeg x) of
        True -> x * (-1)
        False -> x

myMin :: Int -> Int -> Int
myMin a b = case b < a of
        True -> b
        False -> a

myMax :: Int -> Int -> Int
myMax a b = case b > a of
        True -> b
        False -> a

-- step 2
myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

-- step 3
myHead :: [a] -> a
myHead (x:other) = x
myHead[] = error "empty"

myTail :: [a] -> [a]
myTail (x:other) = other
myTail[] = error "empty"

myLength :: [a] -> Int
myLength (x:other) = 1 + myLength other
myLength[] = 0

myNth :: [a] -> Int -> a
myNth (x:xs) n = case n < 0 of
        True -> error "negative range"
        False -> case n >= myLength (x:xs) of
                True -> error "out of range"
                False -> case n == 0  of
                        True -> x
                        False -> myNth xs (n - 1)

myTake :: Int -> [a] -> [a]
myTake n (x:xs) = case n > myLength(x:xs) of
        True -> (x:xs)
        False -> case n < 0 of
                True -> error "out of range"
                False -> case n == 0 of
                        True -> []
                        False -> x : myTake (n - 1) xs

myDrop :: Int -> [a] -> [a]
myDrop i (x:xs) = case i >= myLength (x:xs) of
        True -> []
        False -> case i == 0 of
                True -> (x:xs)
                False -> myDrop (i - 1) xs

myAppend :: [a] -> [a] -> [a]
myAppend [] cpy = cpy
myAppend (x:xs) cpy = x : (myAppend xs cpy)
