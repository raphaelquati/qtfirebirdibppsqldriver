#ifndef __FBTRANSACTION_H__
#define __FBTRANSACTION_H__

//----------------------------------------------------------------

#define TRANSACTION(x) (QSqlDatabase::database().driver()->setProperty("Transaction",(x)))

#define TRANS_SELECT "TAM=amRead, TIL=ilReadCommitted, TLR=lrNoWait, TFF=0"
#define TRANS_UPDATE "TAM=amWrite, TIL=ilConcurrency, TLR=lrNoWait, TFF=0"
#define TRANS_REPORT "TAM=amRead, TIL=ilConcurrency, TLR=lrNoWait, TFF=0"
#define TRANS_DEFAULT "TAM=amWrite, TIL=ilConcurrency, TLR=lrWait, TFF=0"

//----------------------------------------------------------------

#endif // __FBTRANSACTION_H__

