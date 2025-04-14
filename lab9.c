//
// APS105 Lab 9
//
// This is a program written to maintain a personal music library,
// using a linked list to hold the songs in the library.
//
// Author: <Peter Ma>
// Student Number: <1007673055>
//

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the linked list

// Each string in the node is declared as a character pointer variable,
// so they need to be dynamically allocated using the malloc() function,
// and deallocated using the free() function after use.

typedef struct node {
  char *artist;
  char *songName;
  char *genre;
  struct node *next;
} Node;

// A linked list
typedef struct musicLibrary {
  Node *head;
} MusicLibrary;

// Declarations of linked list functions

void initMusicLibrary(MusicLibrary *musicLibrary);
bool insertIntoMusicLibrary(MusicLibrary *musicLibrary, char *songName, char *artist, char *genre);
Node *searchSong(MusicLibrary *musicLibrary, char *songName);
bool isEmpty(MusicLibrary *musicLibrary);
bool insertAtFront(MusicLibrary *musicLibrary, char *songName, char *artist, char *genre);
Node *createNode(char *songName, char *artist, char *genre);
void printMusicLibrary(MusicLibrary *musicLibrary);
void printSong(Node *node);
void searchSongIn(MusicLibrary *musicLibrary, char *song);
bool deleteSong(MusicLibrary *musicLibrary, char *songName);
bool deleteFront(MusicLibrary *musicLibrary);
void freeNode(Node *node);
int deleteAllNodes(MusicLibrary *musicLibrary);

// Declarations of support functions
// See below the main function for descriptions of what these functions do

void inputStringFromUser(char *prompt, char *s, int arraySize);
void songNameDuplicate(char *songName);
void songNameFound(char *songName);
void songNameNotFound(char *songName);
void songNameDeleted(char *songName);
void artistFound(char *artist);
void artistNotFound(char *artist);
void printMusicLibraryEmpty(void);
void printMusicLibraryTitle(void);

const int MAX_LENGTH = 1024;

int main(void) {
  // Declare the head of the linked list.
  MusicLibrary musicLibrary;
  initMusicLibrary(&musicLibrary);

  // Announce the start of the program
  printf("Personal Music Library.\n\n");
  printf("%s", "Commands are I (insert), D (delete), S (search by song name),\n"
               "P (print), Q (quit).\n");

  char response;
  char input[MAX_LENGTH + 1];
  do {
    inputStringFromUser("\nCommand", input, MAX_LENGTH);

    // Response is the first character entered by user.
    // Convert to uppercase to simplify later comparisons.
    response = toupper(input[0]);

    if (response == 'I') {
      // Insert a song into the linked list.
      // Maintain the list in alphabetical order by song name.
      
      char songName[MAX_LENGTH + 1];
      char artist[MAX_LENGTH + 1];
      char genre[MAX_LENGTH + 1];
      char *promptName = "Song name";
      char *promptArtist = "Artist";
      char *promptGenre = "Genre";

      inputStringFromUser(promptName,songName,MAX_LENGTH);
      inputStringFromUser(promptArtist,artist,MAX_LENGTH);
      inputStringFromUser(promptGenre,genre,MAX_LENGTH);

      insertIntoMusicLibrary(&musicLibrary, songName, artist, genre);
      
    } else if (response == 'D') {
      // Delete a song from the list.

      char *prompt = "\nEnter the name of the song to be deleted";
      char songName[MAX_LENGTH + 1];
      inputStringFromUser(prompt,songName,MAX_LENGTH);
      deleteSong(&musicLibrary, songName);

    } else if (response == 'S') {
      // Search for a song by its name.
      char songName[MAX_LENGTH + 1];
      char *prompt = "\nEnter the name of the song to search for";
      inputStringFromUser(prompt,songName,MAX_LENGTH);
      searchSongIn(&musicLibrary, songName);

    } else if (response == 'P') {
      // Print the music library.

      printMusicLibrary(&musicLibrary);

    } else if (response == 'Q') {
      ; // do nothing, we'll catch this below
    } else {
      // do this if no command matched ...
      printf("\nInvalid command.\n");
    }
  } while (response != 'Q');

  // Delete the entire linked list.
  deleteAllNodes(&musicLibrary);

  // Print the linked list to confirm deletion.
  printMusicLibrary(&musicLibrary);

  return 0;
}

// Support Function Definitions

// Prompt the user for a string safely, without buffer overflow
void inputStringFromUser(char *prompt, char *s, int maxStrLength) {
  int i = 0;
  char c;

  printf("%s --> ", prompt);
  while (i < maxStrLength && (c = getchar()) != '\n')
    s[i++] = c;
  s[i] = '\0';
}

// Function to call when the user is trying to insert a song name
// that is already in the personal music library.
void songNameDuplicate(char *songName) {
  printf("\nA song with the name '%s' is already in the music library.\n"
         "No new song entered.\n",
         songName);
}

// Function to call when a song name was found in the personal music library.
void songNameFound(char *songName) {
  printf("\nThe song name '%s' was found in the music library.\n", songName);
}

// Function to call when a song name was not found in the personal music
// library.
void songNameNotFound(char *songName) {
  printf("\nThe song name '%s' was not found in the music library.\n",
         songName);
}

// Function to call when a song name that is to be deleted
// was found in the personal music library.
void songNameDeleted(char *songName) {
  printf("\nDeleting a song with name '%s' from the music library.\n",
         songName);
}

// Function to call when printing an empty music library.
void printMusicLibraryEmpty(void) {
  printf("\nThe music library is empty.\n");
}

// Function to call to print a title when the entire music library is printed.
void printMusicLibraryTitle(void) {
  printf("\nMy Personal Music Library: \n");
}

// Add your functions below this line.

// Funtion to initialize the music library.
void initMusicLibrary(MusicLibrary *musicLibrary) {
  musicLibrary->head = NULL;
}

// Function to insert a song into the music library and keep it in order.
bool insertIntoMusicLibrary(MusicLibrary *musicLibrary, char *songName, char *artist, char *genre) {

  if (searchSong(musicLibrary, songName) != NULL) {
    songNameDuplicate(songName);
    return false;
  }

  if (isEmpty(musicLibrary) || strcmp(songName, musicLibrary->head->songName) < 0) {
    // The list is empty, so insert before the head.
    // The song to insert comes before the current head, so insert before it.
    insertAtFront(musicLibrary, songName, artist, genre);
    return true;
  }
  
  // musicLibrary -> B -> C -> F -> G -> NULL

  Node *current = musicLibrary->head;
  
  // Move the current to the right position.
  while (current->next != NULL && strcmp(songName, current->next->songName) > 0) {
    current = current->next;
  }
  
  Node *newNode = createNode(songName, artist, genre);
  if (newNode == NULL) {
    // Did not allocate memory for a new node
    return false;
  }

  // Link the rest of the list with this new node.
  newNode->next = current->next;
  current->next = newNode;

  return true;
 
}

// Function to find the node with the given song name.
Node *searchSong(MusicLibrary *musicLibrary, char *songName) {

  Node *current = musicLibrary->head;

  while (current != NULL) {
    if (strcmp(current->songName, songName) == 0) {
      // Found the node.
      return current;
    }
    // Did not find the node.
    // Move to the next node in the linked list.
    current = current->next;
  }
  
  return NULL;
}

// Function to check if the linked list is empty.
bool isEmpty(MusicLibrary *musicLibrary) {
  
  if (musicLibrary->head == NULL) {
    return true;
  }
  
  return false;
}

// Function to insert a new node at the front of the linked list.
// Allocate space for a new node and update the list.
bool insertAtFront(MusicLibrary *musicLibrary, char *songName, char *artist, char *genre) {
  
  // Create a new node
  Node *newNode = createNode(songName, artist, genre);
  if (newNode == NULL) {
    return false;
    // Did not allocate enough memory for the new node;
  }
  
  // Update the list
  // The node will be inserted before head, so next should point to head.
  newNode->next = musicLibrary->head;
  // Update head to the new front of the list.
  musicLibrary->head = newNode;
  
  return true;
}

// Function to allocate a new node on the heap
Node *createNode(char *songName, char *artist, char *genre) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  
  if (newNode != NULL) {
    char *newSongName = (char *)malloc((MAX_LENGTH + 1) * sizeof(char));
    char *newArtist = (char *)malloc((MAX_LENGTH + 1) * sizeof(char));
    char *newGenre = (char *)malloc((MAX_LENGTH + 1) * sizeof(char));

    strcpy(newSongName, songName);
    strcpy(newArtist, artist);
    strcpy(newGenre, genre);
    
    newNode->songName = newSongName;
    newNode->artist = newArtist;
    newNode->genre = newGenre;
    newNode->next = NULL;
  }
  
  return newNode;
}

// Function to print out the song of each node of the list.
void printMusicLibrary(MusicLibrary *musicLibrary) {
  if (isEmpty(musicLibrary)) {
    printMusicLibraryEmpty();
    return;
  }

  printMusicLibraryTitle();

  Node *current = musicLibrary->head;

  while(current != NULL) {
    // Print out the song at this node.
    printSong(current);
    // Mode to the next node in the linked list.
    current = current->next;
  }
}

// Function to print out the song of one node.
void printSong(Node *node) {
  if (node != NULL) {
    printf("\n%s\n%s\n%s\n", node->songName, node->artist, node->genre);
  }
}

// Function to find the song with the give song name.
// Print out the infomation.
void searchSongIn(MusicLibrary *musicLibrary, char *songName) {
  
  Node *result = searchSong(musicLibrary, songName);
  
  if (result == NULL) {
    songNameNotFound(songName);
  } else {
    songNameFound(songName);
    printSong(result);
  }
}

// Function to delete the song that mateches a search query.
bool deleteSong(MusicLibrary *musicLibrary, char *songName) {
  if (isEmpty(musicLibrary)) {
    // There is nothing to do in an empty list.
    songNameNotFound(songName);
    return false;
  }

  if (strcmp(songName, musicLibrary->head->songName) == 0) {
    // The first song name matches the value.
    deleteFront(musicLibrary);
    return true;
  }

  // Search for a node that matches the song name but maintain a pointer
  // to the node just before it.
  Node *current = musicLibrary->head;
  while (current->next != NULL && strcmp(current->next->songName, songName) != 0) {
    current  = current->next;
  }
  
  // current now points to a node just before the node that matched,
  // OR current points to the last node.
  if (current->next != NULL) {
    // current does not point to the last node.

    // node is the node we need delete.
    Node *node = current->next;
    // Update the linked list so that node is no longer linked
    current->next = node->next;
    freeNode(node);
    songNameDeleted(songName);
    return true;
    
  }

  songNameNotFound(songName);
  return false;
}

// Function to delete the first node of the linked list.
bool deleteFront(MusicLibrary *musicLibrary) {

  if (isEmpty(musicLibrary)) {
    // The list is empty so there is nothing to delete.
    return false;
  }
  // Save the location of the node after head.
  Node *newHead = musicLibrary->head->next;
  songNameDeleted(musicLibrary->head->songName);
  // Free up the memory userd by the current location.
  freeNode(musicLibrary->head);
  // Update the current head to the saved location.
  musicLibrary->head = newHead;
  
  return true;
  
}

// Function to free the memory allocated for the node and the strings in the node.
void freeNode(Node *node) {
  free(node->songName);
  free(node->artist);
  free(node->genre);
  free(node);
}

// Function to delete every node of the linked list.
int deleteAllNodes(MusicLibrary *musicLibrary) {
  int numDeleted = 0;
  
  while (!isEmpty(musicLibrary)) {
    deleteFront(musicLibrary);
    numDeleted += 1;
  }
  
  musicLibrary->head = NULL;
  
  return numDeleted;
}
