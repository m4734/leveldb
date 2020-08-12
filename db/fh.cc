//cgmin fh.cc

#include "db/fh.h"

#include "util/hash.h"

namespace leveldb {

FH::FH() //cgmin fh imple
{
  bs = 100000;
  fs = 10;
  fv = new unsigned int*[fs];
  int i,j;
  for (i=0;i<fs;i++)
  {
    fv[i] = new unsigned int[bs];
    for (j=0;j<bs;j++)
      fv[i][j] = 0;
    }

}
FH::~FH()
{
  int i;
  for (i=0;i<fs;i++)
    delete fv[i];
  delete fv;
}
void FH::add(const Slice& key)
{
//return;
  int i,hv;
//  printf("????");
//  mutex_.Lock();
  for (i=0;i<fs;i++)
  {
    hv = hash(i,key);
//hv = 0;
//    if (fv[i][hv] < 256)
    if (fv[i][hv] < 4294967295)
      fv[i][hv]++;

//  printf("hv %d fv %d\n",hv,fv[i][hv]);
  }
//  mutex_.Unlock();
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
  return sum;
}
int FH::hash(int fn,const Slice& key)
{
  return Hash(key.data(),key.size(),0xbc9f1d34+fn)%bs;
}


}
