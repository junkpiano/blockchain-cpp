#include <sstream>

#include "Block.h"
#include "Hash.h"

Block::Block(uint32_t nIndexIn, const string &sDataIn): _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr);
    
    sHash = _CalculateHash();
}

void Block::MineBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
    
    string str(cstr);
    
    do {
        _nNonce++;
        sHash = _CalculateHash();
    } while (sHash.substr(0, nDifficulty) != str);
    
    cout << "Block Mined: " << sHash << endl;
}

inline string Block::_CalculateHash() const {
    stringstream ss;
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;
    return Hash(ss.str()).getValue();
}
