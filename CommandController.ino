bool _run = false;
String _JSON;

constexpr unsigned int str2int(const char* str, int h = 0)
{
	return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}


void parseCommand()
{
	Serial.println("Parser");
	if (_run)
	{
		JsonObject& root = buffer.parseObject(_JSON);
		String command = root["text"];
		const char *cCommand = command.c_str();
		switch (str2int(cCommand))
		{
		case str2int("Hello"):
			meh();
			break;
		default:
			break;
		}

		memset(&root, 0, sizeof(root));
		_run = false;
	}
}



void meh()
{
	Serial.println("mehhh");
	state.reserGlobalState();
	noTone(4);

}

