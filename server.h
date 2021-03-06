#ifndef SERVER_H
#define SERVER_H

class Server{
private:
	userList registeredUsers;
	userList onlineUsers;
	cert certificate;
	unsigned char publicKey[128];
	unsigned char privateKey[128];
public:
	/**
	* Checks authenticity of given certificate.
	*
	* @param userCert certficate to be checked
	* @param CApublicKey public key of certification authority
	*
	* @return true when check succesful, false otherwise 
	*/
	bool checkCert(cert userCert , unsigned char* CApublicKey);

	/**
	* Register user into database.
	*
	* @param registeredUsers list with registered users
	* @param login user's login
	* @param pwd user's password
	* @param userCert user's certificate
	*
	* @return zero when succesful, nonzero value when error occurs
	*/
	int registration(userList registeredUsers , unsigned char* login , unsigned char* pwd , cert userCert);

	/**
	* Generates random AES key.
	*
	* @param key generated key
	*
	* @return returns zero when succesful, nonzero value otherwise
	*/
	int randGenAES(unsigned char* key);

	/**
	* Generates random pair of RSA keys.
	*
	* @param publicKey generated public key
	* @param privateKey generated private key
	*
	* @return returns zero when succesful, nonzero value otherwise
	*/
	int randGenRSA(unsigned char* publicKey , unsigned char* privateKey);
		/**
	* Encrypts/decrypts given data with AES - 128.
	* 
	* @param key 128 bit long key
	* @param iv initialisation vector
	* @param data input data
	* @param outData output data
	* @param mode 0 - encryption ; 1 - decryption 
	* 
	* @return returns zero when succesful, nonzero value otherwise
	*/
	int cryptoSym(unsigned char* key , unsigned char* iv , unsigned char* data , unsigned char* outData  , int mode);

	/**
	* Encrypts/decrypts given data with RSA - 1024.
	*
	* @param key 1024 bit long key
	* @param data input data
	* @param outData output data
	* @param mode 0 - encryption ; 1 - decryption
	*
	* @return returns zero when succesful, nonzero value otherwise
	*/
	int cryptoAsym(unsigned char key* , unsigned char* data , unsigned char* outData , int mode);
	
	/**
	* Creates a hash of given data.
	*
	* @param data data to be hashed
	* @param output output of hash
	*
	* @return returns zero when succesful, nonzero value otherwise
	*/
	int hash(unsigned char* data , unsigned char* output);

	/**
	* Sends data to client.
	*
	* @param clientAdress client's adress
	* @param data data to be send
	*
	* @return returns zero when succesful, nonzero value otherwise
	*/
	int sendData(adress clientAdress , unsigned char* data);

	/**
	* Adds user into list of online users.
	*
	* @param onlineUsers list of online users
	* @param login user's login
	*
	* @return returns zero when succesful, nonzero value otherwise
	*/
	int login(userList onlineUsers , unsigned char* login);

	/**
	* Removes user from list of online users.
	*
	* @param onlineUsers list of online users
	* @param login user's login
	*
	* @return returns zero when succesful, nonzero value otherwise
	*/
	int logout(userList onlineUsers , unsigned char* login);
};

#endif //CERTIFICATE_AUTHORITY
