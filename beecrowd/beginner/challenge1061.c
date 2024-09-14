#include <stdio.h>

typedef struct {
    int day,
        hour,
        minute,
        second;
} Datetime;

Datetime create_date(long timestamp);
long get_timestamp_delta(Datetime start_date, Datetime due_date);
Datetime get_date();

int main() {
    Datetime start_date = get_date();
    Datetime due_date = get_date();

    long event_timestamp = get_timestamp_delta(start_date, due_date);

    Datetime timestamp_date = create_date(event_timestamp);

    printf("%d dia(s)\n", timestamp_date.day);
    printf("%d hora(s)\n", timestamp_date.hour);
    printf("%d minuto(s)\n", timestamp_date.minute);
    printf("%d segundo(s)\n", timestamp_date.second);

    return 0;
}

Datetime get_date() {
    char date_pattern[] = "Dia %d";
    char time_pattern[] = "%2d : %2d : %2d";
    char line_buffer[1024];

    int day, hour, minute, second;

    if (fgets(line_buffer, sizeof(line_buffer), stdin)) {
        sscanf(line_buffer, date_pattern, &day);
    }
    
    if (fgets(line_buffer, sizeof(line_buffer), stdin)) {
        sscanf(line_buffer, time_pattern, &hour, &minute, &second);
    }

    Datetime new_date = { day, hour, minute, second};

    return new_date;
}

Datetime create_date(long timestamp) {
    Datetime new_date = {
        .day = timestamp / 86400,
        .hour = (timestamp % 86400) / 3600,
        .minute = ((timestamp % 86400) % 3600) / 60,
        .second = (((timestamp % 86400) % 3600) % 60)
    };

    return new_date;
}

long get_timestamp_delta(Datetime start_date, Datetime due_date) {
    int d_day = start_date.day - due_date.day, 
        d_hour = start_date.hour - due_date.hour, 
        d_minute = start_date.minute - due_date.minute, 
        d_second = start_date.second - due_date.second;

    if (d_day < 0) d_day *= -1;
    if (d_hour < 0) d_hour *= -1;
    if (d_minute < 0) d_minute *= -1;
    if (d_second < 0) d_second *= -1;

    if (start_date.day == due_date.day) 
        return d_day * 86400 + d_hour * 3600 + d_minute * 60 + d_second;

    if (start_date.hour > due_date.hour) {
        d_day--;
        d_hour = 24 - d_hour;
    }

    if (start_date.minute > due_date.minute) {
        d_hour--;
        d_minute = 60 - d_minute;
    }

    if (start_date.second > due_date.second) {
        d_minute--;
        d_second = 60 - d_second;
    }

    return d_day * 86400 + d_hour * 3600 + d_minute * 60 + d_second;
}

