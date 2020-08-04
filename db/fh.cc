//cgmin fh.cc

#include "db/fh.h"

#include "util/hash.h"

namespace leveldb {

FH::FH() //cgmin fh imple
{
  bs = 1000;
  fs = 10;
  fv = new unsigned char*[fs];
  int i,j;
  for (i=0;i<fs;i++)
  {
    fv[i] = new unsigned char[bs];
    for (j=0;j<bs;j++)
      fv[i][j] = 0;
    }

}
FH::~FH()
{
  delete fv;
}
void FH::add(const Slice& key)
{
  int i,hv;
  for (i=0;i<fs;i++)
  {
    hv = hash(i,key);
    if (fv[i][hv] < 256)
      fv[i][hv]++;
  }
}
int FH::get(const Slice& key)
{
  int i,hv,sum;
  sum = 0;
  for (i=0;i<fs;i++)
  {
    hv = hash(i,key);
    sum += fv[i][hv];
  }
  return 0;
}
int FH::hash(int fn,const Slice& key)
{
  return Hash(key.data(),key.size(),0xbc9f1d34+fn)%bs;
}


}
