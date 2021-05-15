#include "client.h"

Client::Client(void) : algorithm(nullptr){}

Client::Client(Algorithm *algorithm) : algorithm(algorithm) {}

void Client::setAlgorithm(Algorithm *algorithm)
{
    delete this->algorithm;
    this->algorithm = algorithm;
}

QString Client::executeAlgorithm(QString currDir, QString currFile)
{
    return this->algorithm->search(currDir, currFile);
}

Client::~Client() { delete this->algorithm; }
