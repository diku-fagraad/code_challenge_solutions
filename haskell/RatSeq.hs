data Node = Node Int Int
instance Show Node where
  show (Node p q) = show p ++ "/" ++ show q

left (Node p q) = Node p (p + q)
right (Node p q) = Node (p + q) q

path :: Int -> [Bool]
path n = reverse $ go n
  where
    go 1 = []
    go n = odd n : go (n `div` 2)

walk :: Node -> [Bool] -> Node
walk n [] = n
walk n (False:p) = walk (left n) p
walk n (True:p) = walk (right n) p

getTest :: IO Int
getTest = do
  l <- getLine
  let n = read $ tail $ dropWhile (/= ' ') l :: Int
  pure n

main = do
  header <- getLine
  let numTests = read header :: Int
  ns <- mapM (const getTest) [1..numTests]
  let results = map (walk (Node 1 1) . path) ns
  mapM_ (\(i, r) -> putStrLn (show i ++ " " ++ show r)) (zip [1..] results)
