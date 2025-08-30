#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/* Amazon 2025 - ROUND 2 Question 

Q. Design a Youtube playlist with the following functionalities: 
    
    a) addSong(songID, songName) => add at the end of playlist. 
    b) deleteSong(songID) => remove song if it exists. 
    c) moveNext() => move to next song. 
    d) moveBack() => move to previous song.
    e) moveByKPositions(int k) => move by k positions.
    f) playlistSize() => give number of songs in the playlist. 

Note: Only moveByKPositions() can be done in O(N) time, rest should work in O(1) time. Focus was on using the right data structure and algorithm, as well as writing clean and modular code.
    
Required Functionalities:

addSong(songID, songName) → append to end (O(1))
deleteSong(songID) → remove song if it exists (O(1))
moveNext() → go to next song (O(1))
moveBack() → go to previous song (O(1))
moveByKPositions(k) → move forward/backward by k positions (O(N) allowed)
playlistSize() → get number of songs (O(1))

🔑 Key Observations:

We need O(1) add at end → suggests Doubly Linked List (DLL).
We need O(1) delete by songID → suggests HashMap (songID → Node reference).
We need moveNext / moveBack O(1) → DLL’s next and prev pointers.
We need O(1) size → maintain a counter.
moveByKPositions(k) can be O(N), so just loop k times.

Thus, the best data structure is:
👉 Doubly Linked List + HashMap (classic LinkedHashMap design idea).
*/

struct Song{
    int id;
    string songName;
    Song* prev;
    Song* next;

    Song(int songID, string name){
        id = songID;
        songName = name;
        prev = NULL;
        next=NULL;
    }
};


class YouTubePlayList{
    public: 

    Song* head;
    Song* current;
    Song* tail;
    int size;

    // {id, (song node)}
    unordered_map<int, Song*>songDB;

    YouTubePlayList(){
        head=NULL;     // represent first song
        tail=NULL;     // represent last song
        current=NULL;  // represent current song
        size=0;        // size of playlist
    }


    // 1. Add new Song at end
    void addSong(int song_id, string song_name){
        Song* newSong = new Song(song_id, song_name);

        if(songDB.find(song_id) != songDB.end()){
            cout<<"Song already present in playlist"<<endl;
            return;
        }

        songDB[song_id] = newSong;

        if(head==NULL){
            head = current = tail = newSong;
        }
        else{ // Adding song at tail i.e last 
            tail->next = newSong;
            newSong->prev = tail;
            tail=tail->next;
        }
        size++;
    }


    // b) Delete song
    void deleteSong(int song_id){
        if(songDB.find(song_id) == songDB.end()){
            cout<<"Song ID not exist!"<<endl;
            return;
        }

        // song node to delete
        Song* todelete = songDB[song_id];

        if(todelete == current){
            if(todelete->next != NULL){
                current = todelete->next;
            }else{
                current = todelete->prev;
            }
        }

        
        if(todelete == head){
            head = head->next;
            if (head!=NULL) head->prev=NULL;
        }

        else if (todelete == tail){
            tail =  todelete->prev;
            if (tail) tail->next = NULL;
        }

        else{
            todelete->prev->next = todelete->next;
            todelete->next->prev = todelete->prev;
        }

        delete todelete;

        songDB.erase(song_id);
        size--;
        cout << "Song id: " << song_id << " deleted successfully." << endl;
    }

    // c) Move next
    void moveNext() {
        if (current && current->next != NULL){
            current = current->next;
            string songName = current->songName;
            cout<<songName<<" is playing now"<<endl;
        }
        else{
            cout<<"No Next Song"<<endl;
        }
    }

    // d) Move back
    void moveBack() {
        if (current && current->prev != NULL){
            current = current->prev;
            string songName = current->songName;
            cout<<songName<<" is playing now"<<endl;
        }
        else{
            cout<<"No previous Song"<<endl;
        }
    }

    // e) Move by k positions
    void moveByKPositions(int k){
        while(current->next != NULL && k != 0){
            current = current->next;
            k--;
        }
    }

    // f) Playlist size
    void playlistSize() {
        cout<<"Playlist size = "<< size<<endl;
    }

    void currentSongPlaying(){
        if(current == NULL){
            cout<<"Empty Playlist"<<endl;
        }else{
            string songName = current->songName;
            cout<<songName<<" is playing now"<<endl;
        }
    }

};



int main(){
    YouTubePlayList y;

    y.addSong(1,"A");
    y.addSong(2,"B");
    y.addSong(3,"C");
    y.addSong(4,"D");
    y.addSong(5,"E");
    y.addSong(6,"F");
    y.addSong(7,"G");
    y.addSong(8,"H");

}