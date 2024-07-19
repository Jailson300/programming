import random

class Ludo:
    def __init__(self):
        self.position = -1  # -1 means the piece is in the initial block
        self.home_position = 56  # Position at which the player wins

    def roll_dice(self):
        return random.randint(1, 6)

    def move(self):
        if self.position == -1:
            print("You need to roll a 6 to move out of the initial block.")
            while True:
                dice = self.roll_dice()
                print(f"Dice rolled: {dice}")
                if dice == 6:
                    self.position = 0
                    print("Piece moved out of the initial block.")
                    break
                else:
                    print("Try again.")
        else:
            while True:
                dice = self.roll_dice()
                print(f"Dice rolled: {dice}")
                if self.position + dice > self.home_position:
                    print(f"Cannot move, you need exactly {self.home_position - self.position} to reach home.")
                    continue
                else:
                    self.position += dice
                    print(f"Piece moved to position {self.position}.")
                    if self.position == self.home_position:
                        print("Congratulations! You've reached home and won the game.")
                        break
                if dice != 6:
                    break

    def play_game(self):
        while self.position != self.home_position:
            input("Press Enter to roll the dice.")
            self.move()

# Start the game
game = Ludo()
game.play_game()
