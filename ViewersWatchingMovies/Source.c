#include <stdio.h>
#include <stdlib.h>

typedef struct Video {
    char* name;
    int unique_views;
} Video;

typedef struct Viewer {
    char* username;
    Video* watched_videos;
    int watched_videos_size;
} Viewer;

int count_views(Viewer** viewers, int viewers_size, char* video_name)
{
    int result = 0;

    for (int i = 0; i < viewers_size; i++)
    {
        for (int j = 0; j < viewers[i]->watched_videos_size; j++)
        {
            if ((*video_name) == *(viewers[i]->watched_videos[j].name))
            {
                result++;
                break;
            }
        }
    }

    return result;
}

int main()
{
    Video videos[] = { {.name = "Soccer", .unique_views = 500},
                           {.name = "Basketball", .unique_views = 1000} };
    Viewer viewer = { .username = "Dave", .watched_videos = videos,
                     .watched_videos_size = 2 };

    Viewer* viewers[] = { &viewer };
    printf("%d", count_views(viewers, 1, (char*)"Soccer")); /* should print 1 */
}
