
#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

void DCMOTOR1_VidInit(void);
void DCMOTOR1_VidRotate(u8 direction,u8 direction2);
void DCMOTOR2_VidInit(void);
void DCMOTOR_VidRotateright(void);
void DCMOTOR_VidRotateleft(void);
void DCMOTOR_VidRotatebackward(void);
void DCMOTOR_VidRotateforward(void);
void DCMOTOR_VidRotate180(void);
void DCMOTOR_VidRotatestop(void);
void DCMOTOR_CHOOSE(u8 target);
#endif /* DCMOTOR_INTERFACE_H_ */
