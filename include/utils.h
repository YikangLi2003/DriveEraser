#ifndef UTILS_H
#define UTILS_H

typedef char Timestamp[20];
typedef char Path[4096];
typedef char Uuid4[37];

bool get_timestamp(Timestamp buffer);
bool input_path(Path path);
void get_uuid4(Uuid4 uuid);

#endif