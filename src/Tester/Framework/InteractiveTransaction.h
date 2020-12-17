#ifndef _MENCI_TRANSACTION_TESTER_FRAMEWORK_INTERACTIVE_TRANSACTION_H
#define _MENCI_TRANSACTION_TESTER_FRAMEWORK_INTERACTIVE_TRANSACTION_H

#include <memory>

#include "Operation.h"
#include "Algorithm/Transaction.h"

class InteractiveTransaction {
    Transaction transaction;
    enum {
        RUNNING, ROLLED_BACK, COMMITED
    } status;
    std::shared_ptr<std::vector<Operation>> operations;

    InteractiveTransaction(size_t id, std::shared_ptr<std::vector<Operation>> operations);
    void ensureRunning(const char *methodName);
    void rollback();

    friend class TransactionRunner;

public:
    bool read(const RecordKey &key, RecordData &result);
    bool write(const RecordKey &key, const RecordData &newData);
    bool commit();
};

#endif // _MENCI_TRANSACTION_TESTER_FRAMEWORK_INTERACTIVE_TRANSACTION_H