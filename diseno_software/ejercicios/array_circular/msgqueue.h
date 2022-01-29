#ifndef MSGQUEUE_H_INCLUDED
#define MSGQUEUE_H_INCLUDED

// NOTES FOR IMPLEMENTATION OF METHODS FROM THIS CLASS
// Msgqueue class represents a fixed-size queue that can hold up a user-specified number of elements N.
// This number N shall always be less than QUEUE_BUFFER_SIZE, this is needed to be checked.
// The queue will be handled as a 2-index circular buffer with N+1 elements.
// Thus, the queue array will have space for N+1 elements.
// There are two indexes, that will point to the "first valid element" (extract index)
// and the "next free spot" (insert index) respectively.
// Both indexes always increment on operations (never decrement),
// and perform a rollover from index N to index 0.
// Note that "insert" index is always higher or equal to "extract" index, taking into account rollover.
// The empty condition is reached when both point to the same position, i.e. "insert" = "extract".
// The full condition is reached when "insert" - "extract" = N (taking into account the rollover),
// which is equivalent to check "extract" - "insert" = 1.
// The insert function will increase the "insert" index,
// while the extract function will increase the "extract" index.


typedef struct
{
    char* data; // array where element data are stored; to be handled as a circular buffer
    int num_bytes; // real number of bytes of each element stored in queue
} tQueueElement;


class Msgqueue
{
  public:

    Msgqueue(int max_elements); // constructor
    ~Msgqueue(void); // destructor
    bool is_queue_full( void ) const; // returns TRUE if queue is full, FALSE otherwise
    bool is_queue_empty( void ) const; // returns TRUE if queue is empty, FALSE otherwise
    bool insert_element( const char new_element[], const int bytes ); // inserts element with size "bytes" in queue
                                                                      // returns TRUE if inserted, FALSE otherwise
    int extract_element( char element[] ); // extracts element from queue, returns size in bytes (0 if empty)
    int get_number_of_elements( void ) const; // returns number of elements currently stored in queue (0 if empty)

  private:

    static const int QUEUE_BUFFER_SIZE = 100; // maximum buffer size (must be greater than max_num_elements)

    int insert_index; // insert index
    int extract_index; // extract index
    int max_num_elements; // maximum elements in queue, given in constructor, should be less than QUEUE_BUFFER_SIZE
    tQueueElement buffer[QUEUE_BUFFER_SIZE]; // buffer to hold messages

};

#endif // MSGQUEUE_H_INCLUDED
