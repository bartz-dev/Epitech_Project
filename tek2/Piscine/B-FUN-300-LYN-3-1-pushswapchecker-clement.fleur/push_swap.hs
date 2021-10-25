--
-- EPITECH PROJECT, 2021
-- B-FUN-300-LYN-3-1-pushswapchecker-clement.fleur
-- File description:
-- push_swap
--

import System.Environment ( getArgs )
import qualified Data.Text as T
import Data.Char
import System.Exit
import Data.Maybe
import Data.List
import Text.Read

data ListDiv = L_a | L_b
type Lists = ([Int], [Int])
data Arg = Sa | Sb | Sc
            | Pa | Pb
            | Ra | Rb | Rr
            | Rra | Rrb | Rrr deriving (Show, Eq, Read)

main :: IO ()
main =do
    argv <- getArgs
    swapper <- getLine
    let toDo = transform $ dropWord $ words swapper
    let step = transform $ getInt argv
    case step of
       Nothing -> exitWith $ ExitFailure 84
       Just x -> case toDo of
            Nothing -> exitWith $ ExitFailure 84
            Just y -> printSwap $ swape (x, []) y

printSwap :: Lists -> IO ()
printSwap (xs, []) = case xs == sort xs of
                    True -> putStrLn "OK"
                    False -> putStrLn ("KO: (" ++ show xs ++ ",[])")
printSwap (xs, ys) = putStrLn ("KO: " ++ show(xs, ys))

transform :: [Maybe a] -> Maybe [a]
transform [] = Just []
transform xs
    | length xs == length res = Just (res)
    | otherwise = Nothing
    where res = catMaybes xs

swape :: Lists -> [Arg] -> Lists
swape lists [] = lists
swape lists args = foldl toExec lists args

toExec :: Lists -> Arg -> Lists
toExec (xs, ys) Sa = (sab xs, ys)
toExec (xs, ys) Sb = (xs,sab ys)
toExec (xs, ys) Sc = (sab xs,sab ys)
toExec lists Pa = getList lists L_a
toExec lists Pb = getList lists L_b
toExec (xs, ys) Ra = (rab xs, ys)
toExec (xs, ys) Rb = (xs,rab ys)
toExec (xs, ys) Rr = (rab xs,rab ys)
toExec (xs, ys) Rra = (rrab xs, ys)
toExec (xs, ys) Rrb = (xs,rrab ys)
toExec (xs, ys) Rrr = (rrab xs,rrab ys)

convertString :: String -> Maybe Arg
convertString [] = Nothing
convertString (x:xs) = readMaybe $ (toUpper x):xs

dropWord :: [String] -> [Maybe Arg]
dropWord [] = []
dropWord c = map convertString c

getInt :: [String] -> [Maybe Int]
getInt [] = []
getInt xs = map readMaybe xs

getList :: Lists -> ListDiv -> Lists
getList (as, []) L_a = (as, [])
getList (as, (b:bs)) L_a = ((b:as), bs)
getList ([], bs) L_b = ([], bs)
getList ((a:as), bs) L_b = (as, (a:bs))

sab :: [Int] -> [Int]
sab [] = []
sab (x:[]) = (x:[])
sab (x:y:xs) = (y:x:xs)

rrab :: [Int] -> [Int]
rrab [] = []
rrab (x:[]) = (x:[])
rrab x = [last x] ++ init x

rab :: [Int] -> [Int]
rab [] = []
rab (y:[]) = (y:[])
rab (x:xs) = xs ++ [(x:xs)!!0]