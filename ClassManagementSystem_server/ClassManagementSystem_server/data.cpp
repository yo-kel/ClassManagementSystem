#include "data.h"

Data_login::Data_login(std::string sid, std::string pwd, std::string position) {
    this->sid = sid;
    this->pwd = pwd;
    this->position = position;
}
Data_login::Data_login() {
    sid = "";
    pwd = "";
    position = "";
}

std::string DataSerialize(Data data) {
    //std::string res = "";
    std::ostringstream archive_stream;
    boost::archive::text_oarchive archive(archive_stream);
    archive << data;
    return archive_stream.str();
}

Data DataDeserialize(std::string string) {
    std::istringstream archive_stream(string);
    boost::archive::text_iarchive archive(archive_stream);
    Data data;
    archive >> data;
    return data;
}

