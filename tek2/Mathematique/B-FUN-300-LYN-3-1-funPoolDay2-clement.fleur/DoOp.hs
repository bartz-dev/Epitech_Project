--
-- EPITECH PROJECT, 2021
-- B-FUN-300-LYN-3-1-funPoolDay2-clement.fleur
-- File description:
-- DoOp
--

module DoOp where

import Data.Maybe
import Data.String

myElem :: Eq a => a -> [a] -> Bool
myElem list [] = False
myElem list (x:xs) = case list == x of
                    True -> True
                    False -> myElem list xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv f 0 = Nothing
safeDiv f d = Just(f `div` d)

safeNth :: [a] -> Int -> Maybe a
safeNth [] n = Nothing
safeNth (x:xs) n | length (x:xs) < n = Nothing
                 | n == 0 = Just x
                 | otherwise = safeNth xs (n - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc n = case n of
            Just n -> Just (n + 1)
            Nothing -> Nothing
            
safeSuccF :: Maybe Int -> Maybe Int
safeSuccF n = fmap(\x -> x + 1) n

safeSuccOp :: Maybe Int -> Maybe Int
safeSuccOp n = n >>= (\x -> Just (x + 1))

myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup n [] = Nothing
myLookup n (x:xs) | n == fst x = Just (snd x)
                  | otherwise = myLookup n xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo fct Nothing b = Nothing
maybeDo fct a Nothing = Nothing
maybeDo fct (Just a) (Just b) = Just (fct a b)

myDigit :: Char -> Bool
myDigit c | c `elem` "0123456789" = True
          | otherwise = False

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt c = case all myDigit c of
    True -> Just (read c::Int)
    False -> Nothing

getLineLength :: IO Int
getLineLength = do x <- getLine
                   return $ length x