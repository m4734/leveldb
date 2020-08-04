//cgmin db/fh.h

#ifndef STORAGE_LEVELDB_DB_FH_H_
#define STORAGE_LEVELDB_DB_FH_H_

#include "leveldb/slice.h"

namespace leveldb {

class FH //cgmin FH
{
  public:
    FH();
    ~FH();

    unsigned char** fv; //byte
    int bs; // bucket size
    int fs; // function size

    void add(const Slice& key); //key
    int get(const Slice& key); //key
    int hash(int fn,const Slice& key);
};

}

#endif
