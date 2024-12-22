# Memory Match Card Game

## General Description
The **Memory Match Card Game** is a turn-based game where two players compete by flipping cards from a hidden grid. Players score points by matching cards or interacting with special cards that influence the game dynamics. The player with the highest score at the end of the game wins.

## Gameplay Overview

### Player Turns and Card Flipping
- Two players take alternating turns.
- Each turn, a player selects two cards by entering their grid coordinates.
- The selected cards are flipped and revealed.

### Scoring Rules
1. **Standard Cards:**
   - **Match**: Gain 1 point, take another turn, and remove cards from the grid.
   - **No Match**: Cards are flipped back; the turn ends.
2. **Bonus Cards (Number 7):**
   - **Single Bonus Card + Standard Card**: Gain 1 point; bonus card removed.
   - **Two Bonus Cards**:
     - Gain 2 points, or
     - Gain 1 point and take another turn. Both cards removed.
3. **Penalty Cards (Number 8):**
   - **Single Penalty Card + Standard Card**: Lose 1 point.
   - **Two Penalty Cards**:
     - Lose 2 points, or
     - Lose 1 point and skip the next turn. Both cards removed.
4. **Bonus Card + Penalty Card**: No effect on score; both cards removed.

### Game End and Winner Determination
- The game ends when all card pairs are matched.
- The player with the highest score wins.
- A tie is declared if scores are equal.

## Class Design

### Card Class and Subclasses
- **StandardCard, BonusCard, PenaltyCard**:
  - Methods: `reveal()`, `hide()`, `display()`.
  - Implement specific scoring rules for each card type.

### Player Class
- Tracks player name and score.
- Methods to increase/decrease score based on card effects.

### Deck Class
- Manages the grid and cards.
- Handles grid reset, card removal, and grid display.

### Game Class
- Controls the main game logic:
  - Player turns, card flipping, scoring updates.
  - Special card effects and end-of-game logic.

## Game Flow
1. **Initial Setup**:
   - Display the grid with all cards hidden (`*`).
   - Show player names and scores.
2. **Player Turn**:
   - Prompt the player to select two cards by entering coordinates.
   - Reveal selected cards and apply scoring rules.
   - Update and display the grid and scores.
3. **Turn Transition**:
   - Flip unmatched cards back.
   - Switch to the next player.
4. **Game Continuation**:
   - Repeat turns until all pairs are matched.
5. **Game End**:
   - Announce the game end and the winner or a tie.

## Features
- **Turn-Based Gameplay**: Alternating turns with dynamic score adjustments.
- **Special Card Effects**: Bonus and penalty cards add strategic depth.
- **Winner Announcement**: Clear end-game results.
- **Dynamic Grid Display**: Updated after each turn.

## How to Play
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/memory-match-game.git
   cd memory-match-game
