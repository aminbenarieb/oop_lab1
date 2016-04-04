#ifndef CONFIG_H
#define CONFIG_H

#define kTextTitle "Carcas Model Vievew"

#define kBtnTextLoad "Load model"

#define kMsgFileNotFound  "Файл не найден!"
#define kMsgFileCorrupted "Файл поврежден или содержит некоректные данные!"
#define kMsgFileOutMemory "Недостаточно памяти для загрязки модели!"
#define kMsgUnknowError   "Неизвестная ошибка, что-то пошло не так"

#define kDrawPenWidth 2
#define kPadding 20
#define kMouseSensetivity 30.0

#define kmin(a, b) ( ( a < b) ? a : b )
#define kmax(a, b) ( ( a > b) ? a : b )
#define kRadianToDegree(radian) ( radian*180/M_PI )


#endif // CONFIG_Hs
