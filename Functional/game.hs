
{-
  Hunt The Wumpus Game
  Paradigms Programming Lab
  Federal Univesity Of Campina Grande,
  Computer Science - 2017.1
-}

import Data.List

-- cria os simbolos do jogo
data Symbl = Player | Gold | Pit | Stench | Breeze | Wumpus | Undef
  deriving (Eq, Ord, Show, Enum)

-- cria um tipo Mapa
type Mapa = [[Symbl]]

main = do
  putStrLn ("fim do programa.")
