#pragma once


#include "Client.hpp"
#include <unordered_map>
// #include "Server.hpp"




class Channel
{
public :
	Channel();
	Channel(const std::string& _channelName);
	~Channel();
	void AddUser2Channel(Client* User);
	void setCreation(bool val);
	bool getCreation() const;
	std::string getChannelName() const;

	Channel createChannel(std::string name);

	std::vector<Client> *getChannelClientsVector()
	{
		return &(channelClients);
	}

	void sendMsg2All(int sender, std::string msg)
	{
		size_t i = 0;
		while (i != channelClients.size())
		{
			if (sender == channelClients[i].getClientSock())
				i++;
			send(channelClients[i].getClientSock(), msg.c_str(), msg.size(), 0);
			i++;
		}
	}

	std::string getChannelClientByName()
	{
		std::string names;
		size_t i = 0;
		while (i < channelClients.size())
		{
			names += channelClients[i].getNickName();
			i++;
			if (i < channelClients.size())
				names += "\n";
		}
		return names;
	}
	void printname()
	{
		size_t i = 0;
		while (i != channelClients.size())
		{
			std::cout << channelClients[i].getNickName() << std::endl;;
			i++;
		}
	}


private :
	std::string channelName;
	bool isCreated;
	std::vector<Client> channelClients;
	bool hasPasswd;
	std::string channelPasswd;
};

