/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hangman;

import java.util.Scanner;

/**
 *
 * @author Workspace
 */
public class Hangman {

  public static void main(String[] args) {
    // Your incredible code goes here...
    /*
    if(args.length == 0) {
      System.out.println("Usage: java Hangman <answer>");
      System.err.println("answer is required");
      System.exit(1);
    }
    */
    Scanner inputFromUser = new Scanner(System.in);
    
    System.out.println("Enter the word to be guessed:A");
    
    Game game = new Game(inputFromUser.nextLine());
    Prompter prompter = new Prompter(game);
    
    while(game.getRemainingTries() > 0  && !game.isWon()) {
      prompter.displayProgress();
      prompter.promptForGuess();
    }
    
    prompter.displayOutcome();
  }
}
