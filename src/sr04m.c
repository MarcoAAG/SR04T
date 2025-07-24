/**********************************************************************************************************************
 * \file sr04m.c
 *
 * \author MarcoAAG
 *
 * \date May-03-2025
 *
 * \version 1.0 \n \n
 *
 * \brief Implementation of the SR04M driver
 *
 *********************************************************************************************************************/

/* ============================================================================================== */
/*                                         Include Files                                          */
/* ============================================================================================== */
#include <sr04m.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================================== */
/*                                    Private Function Prototypes                                 */
/* ============================================================================================== */

/** **********************************************************************************************
 * \defgroup SR04M_Private_IO Internal Register Access Wrappers
 * \brief Internal static functions used to abstract register-level read/write operations.
 * @{
 */

/**
 * \brief Wrapper function to perform a register read using SR04M_Object.
 *
 * Forwards the read request to the function pointer defined in the `SR04M_IO` interface.
 *
 * \param[in]  p_handle Pointer to the SR04M_Object instance (cast to void*).
 * \param[out] p_data   Pointer to the buffer where data will be stored.
 * \param[in]  u_length Number of bytes to read.
 *
 * \return Status code returned by the underlying `readReg` function.
 */
static uint32_t SR04M_ReadRegWrap(void* p_handle, uint8_t* p_data, uint8_t u_length);

/**
 * \brief Wrapper function to perform a register write using SR04M_Object.
 *
 * Forwards the write request to the function pointer defined in the `SR04M_IO` interface.
 *
 * \param[in] p_handle Pointer to the SR04M_Object instance (cast to void*).
 * \param[in] p_data   Pointer to the buffer containing data to write.
 * \param[in] u_length Number of bytes to write.
 *
 * \return Status code returned by the underlying `writeReg` function.
 */
static uint32_t SR04M_WriteRegWrap(void* p_handle, uint8_t* p_data, uint8_t u_length);

/**
 * \brief Performs a register read through the driver context.
 *
 * Uses the read function and handle stored in the `SR04M_CTX` to perform the operation.
 *
 * \param[in]  p_ctx    Pointer to the SR04M_CTX structure.
 * \param[out] p_data   Pointer to the buffer where data will be stored.
 * \param[in]  u_length Number of bytes to read.
 *
 * \return Status code returned by the context's `readReg` function.
 */
static uint32_t SR04M_read_reg(SR04M_CTX* p_ctx, uint8_t* p_data, uint8_t u_length);

/**
 * \brief Performs a register write through the driver context.
 *
 * Uses the write function and handle stored in the `SR04M_CTX` to perform the operation.
 *
 * \param[in] p_ctx    Pointer to the SR04M_CTX structure.
 * \param[in] p_data   Pointer to the buffer containing data to write.
 * \param[in] u_length Number of bytes to write.
 *
 * \return Status code returned by the context's `writeReg` function.
 */
static uint32_t SR04M_write_reg(SR04M_CTX* p_ctx, uint8_t* p_data, uint8_t u_length);

/** @} */ // end of SR04M_Private_IO

/* ============================================================================================== */
/*                                         Public Functions                                       */
/* ============================================================================================== */

uint8_t SR04M_u_Init(SR04M_Object* p_obj, SR04M_IO* p_io)
{
  uint8_t u_ret = SR04M_OK;

  if(p_obj == NULL)
  {
    u_ret = SR04M_ERROR;
  }
  else
  {
    p_obj->io.writeReg = p_io->writeReg;
    p_obj->io.readReg  = p_io->readReg;

    p_obj->ctx.readReg  = SR04M_ReadRegWrap;
    p_obj->ctx.writeReg = SR04M_WriteRegWrap;
    p_obj->ctx.handle   = p_obj;
  }

  return u_ret;
}

uint16_t SR04M_u_GetDistance(SR04M_Object* p_obj)
{
  uint16_t u_distance    = 0u;
  uint8_t  a_txBuffer[1] = { 0x55 };
  uint8_t  a_rxBuffer[4];

  SR04M_write_reg(&p_obj->ctx, a_txBuffer, 1);
  SR04M_read_reg(&p_obj->ctx, a_rxBuffer, 4);
  u_distance = ((uint16_t)a_rxBuffer[1] << 8) | (uint16_t)a_rxBuffer[2];

  return u_distance;
}

/* ============================================================================================== */
/*                                         Private Functions                                      */
/* ============================================================================================== */

static uint32_t SR04M_ReadRegWrap(void* p_handle, uint8_t* p_data, uint8_t u_length)
{
  SR04M_Object* p_obj = (SR04M_Object*)p_handle;

  return p_obj->io.readReg(p_data, u_length);
}

static uint32_t SR04M_WriteRegWrap(void* p_handle, uint8_t* p_data, uint8_t u_length)
{
  SR04M_Object* p_obj = (SR04M_Object*)p_handle;

  return p_obj->io.writeReg(p_data, u_length);
}

static uint32_t SR04M_read_reg(SR04M_CTX* p_ctx, uint8_t* p_data, uint8_t u_length)
{
  return p_ctx->readReg(p_ctx->handle, p_data, u_length);
}

static uint32_t SR04M_write_reg(SR04M_CTX* p_ctx, uint8_t* p_data, uint8_t u_length)
{
  return p_ctx->writeReg(p_ctx->handle, p_data, u_length);
}

#ifdef __cplusplus
}
#endif
