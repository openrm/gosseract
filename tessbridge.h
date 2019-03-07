#ifdef __cplusplus
extern "C" {
#endif

typedef void* TessBaseAPI;
typedef void* PixImage;

struct orient_result {
    bool success;
    int orient_deg;
    float orient_conf;
    char* script_name;
    float script_conf;
};

struct bounding_box {
    int x1,y1,x2,y2;
    char* word;
    float confidence;
};

struct bounding_boxes {
    int length;
    struct bounding_box* boxes;
};

TessBaseAPI Create(void);

void Free(TessBaseAPI);
void Clear(TessBaseAPI);
void ClearPersistentCache(TessBaseAPI);
int Init(TessBaseAPI, char*, char*, char*, char*);
struct orient_result* DetectOrientationScript(TessBaseAPI);
struct bounding_boxes* GetBoundingBoxes(TessBaseAPI, int);
bool SetVariable(TessBaseAPI, char*, char*);
void SetPixImage(TessBaseAPI a, PixImage pix);
void SetSourceResolution(TessBaseAPI, int);
void SetPageSegMode(TessBaseAPI, int);
int GetPageSegMode(TessBaseAPI);
char* UTF8Text(TessBaseAPI);
char* HOCRText(TessBaseAPI);
const char* Version(TessBaseAPI);

PixImage CreatePixImageByFilePath(char*);
PixImage CreatePixImageFromBytes(unsigned char*, int);
void DestroyPixImage(PixImage pix);

#ifdef __cplusplus
}
#endif/* extern "C" */
