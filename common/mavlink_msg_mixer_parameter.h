#pragma once
// MESSAGE MIXER_PARAMETER PACKING

#define MAVLINK_MSG_ID_MIXER_PARAMETER 235

MAVPACKED(
typedef struct __mavlink_mixer_parameter_t {
 float param_values[8]; /*< Array of parameter values*/
 uint16_t count; /*< Total number of onboard parameters*/
 uint16_t index; /*< Index of this onboard parameter*/
 uint16_t mixer_index; /*< Index of the mixer in the group*/
 uint16_t parameter_index; /*< Index of the parameter in a mixer or something else*/
 uint8_t mixer_group; /*< Access to different sets of mixers*/
 uint8_t mixer_sub_index; /*< Index of the sub mixer in the mixer*/
 uint8_t mixer_type; /*< Implementation specific identifier for mixer type*/
 uint8_t param_type; /*< Parameter type: see the MAV_PARAM_TYPE enum for supported data types.*/
 uint8_t param_array_size; /*< Size of the array for this parameter*/
 char param_id[16]; /*< Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string*/
}) mavlink_mixer_parameter_t;

#define MAVLINK_MSG_ID_MIXER_PARAMETER_LEN 61
#define MAVLINK_MSG_ID_MIXER_PARAMETER_MIN_LEN 61
#define MAVLINK_MSG_ID_235_LEN 61
#define MAVLINK_MSG_ID_235_MIN_LEN 61

#define MAVLINK_MSG_ID_MIXER_PARAMETER_CRC 36
#define MAVLINK_MSG_ID_235_CRC 36

#define MAVLINK_MSG_MIXER_PARAMETER_FIELD_PARAM_VALUES_LEN 8
#define MAVLINK_MSG_MIXER_PARAMETER_FIELD_PARAM_ID_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MIXER_PARAMETER { \
    235, \
    "MIXER_PARAMETER", \
    11, \
    {  { "param_values", NULL, MAVLINK_TYPE_FLOAT, 8, 0, offsetof(mavlink_mixer_parameter_t, param_values) }, \
         { "count", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_mixer_parameter_t, count) }, \
         { "index", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_mixer_parameter_t, index) }, \
         { "mixer_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_mixer_parameter_t, mixer_index) }, \
         { "parameter_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_mixer_parameter_t, parameter_index) }, \
         { "mixer_group", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_mixer_parameter_t, mixer_group) }, \
         { "mixer_sub_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_mixer_parameter_t, mixer_sub_index) }, \
         { "mixer_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_mixer_parameter_t, mixer_type) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_mixer_parameter_t, param_type) }, \
         { "param_array_size", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_mixer_parameter_t, param_array_size) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 45, offsetof(mavlink_mixer_parameter_t, param_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MIXER_PARAMETER { \
    "MIXER_PARAMETER", \
    11, \
    {  { "param_values", NULL, MAVLINK_TYPE_FLOAT, 8, 0, offsetof(mavlink_mixer_parameter_t, param_values) }, \
         { "count", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_mixer_parameter_t, count) }, \
         { "index", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_mixer_parameter_t, index) }, \
         { "mixer_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_mixer_parameter_t, mixer_index) }, \
         { "parameter_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_mixer_parameter_t, parameter_index) }, \
         { "mixer_group", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_mixer_parameter_t, mixer_group) }, \
         { "mixer_sub_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_mixer_parameter_t, mixer_sub_index) }, \
         { "mixer_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_mixer_parameter_t, mixer_type) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_mixer_parameter_t, param_type) }, \
         { "param_array_size", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_mixer_parameter_t, param_array_size) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 45, offsetof(mavlink_mixer_parameter_t, param_id) }, \
         } \
}
#endif

/**
 * @brief Pack a mixer_parameter message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param count Total number of onboard parameters
 * @param index Index of this onboard parameter
 * @param mixer_group Access to different sets of mixers
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param mixer_type Implementation specific identifier for mixer type
 * @param parameter_index Index of the parameter in a mixer or something else
 * @param param_type Parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 * @param param_array_size Size of the array for this parameter
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_values Array of parameter values
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mixer_parameter_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t count, uint16_t index, uint8_t mixer_group, uint16_t mixer_index, uint8_t mixer_sub_index, uint8_t mixer_type, uint16_t parameter_index, uint8_t param_type, uint8_t param_array_size, const char *param_id, const float *param_values)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_PARAMETER_LEN];
    _mav_put_uint16_t(buf, 32, count);
    _mav_put_uint16_t(buf, 34, index);
    _mav_put_uint16_t(buf, 36, mixer_index);
    _mav_put_uint16_t(buf, 38, parameter_index);
    _mav_put_uint8_t(buf, 40, mixer_group);
    _mav_put_uint8_t(buf, 41, mixer_sub_index);
    _mav_put_uint8_t(buf, 42, mixer_type);
    _mav_put_uint8_t(buf, 43, param_type);
    _mav_put_uint8_t(buf, 44, param_array_size);
    _mav_put_float_array(buf, 0, param_values, 8);
    _mav_put_char_array(buf, 45, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MIXER_PARAMETER_LEN);
#else
    mavlink_mixer_parameter_t packet;
    packet.count = count;
    packet.index = index;
    packet.mixer_index = mixer_index;
    packet.parameter_index = parameter_index;
    packet.mixer_group = mixer_group;
    packet.mixer_sub_index = mixer_sub_index;
    packet.mixer_type = mixer_type;
    packet.param_type = param_type;
    packet.param_array_size = param_array_size;
    mav_array_memcpy(packet.param_values, param_values, sizeof(float)*8);
    mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MIXER_PARAMETER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MIXER_PARAMETER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MIXER_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_MIXER_PARAMETER_LEN, MAVLINK_MSG_ID_MIXER_PARAMETER_CRC);
}

/**
 * @brief Pack a mixer_parameter message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param count Total number of onboard parameters
 * @param index Index of this onboard parameter
 * @param mixer_group Access to different sets of mixers
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param mixer_type Implementation specific identifier for mixer type
 * @param parameter_index Index of the parameter in a mixer or something else
 * @param param_type Parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 * @param param_array_size Size of the array for this parameter
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_values Array of parameter values
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mixer_parameter_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t count,uint16_t index,uint8_t mixer_group,uint16_t mixer_index,uint8_t mixer_sub_index,uint8_t mixer_type,uint16_t parameter_index,uint8_t param_type,uint8_t param_array_size,const char *param_id,const float *param_values)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_PARAMETER_LEN];
    _mav_put_uint16_t(buf, 32, count);
    _mav_put_uint16_t(buf, 34, index);
    _mav_put_uint16_t(buf, 36, mixer_index);
    _mav_put_uint16_t(buf, 38, parameter_index);
    _mav_put_uint8_t(buf, 40, mixer_group);
    _mav_put_uint8_t(buf, 41, mixer_sub_index);
    _mav_put_uint8_t(buf, 42, mixer_type);
    _mav_put_uint8_t(buf, 43, param_type);
    _mav_put_uint8_t(buf, 44, param_array_size);
    _mav_put_float_array(buf, 0, param_values, 8);
    _mav_put_char_array(buf, 45, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MIXER_PARAMETER_LEN);
#else
    mavlink_mixer_parameter_t packet;
    packet.count = count;
    packet.index = index;
    packet.mixer_index = mixer_index;
    packet.parameter_index = parameter_index;
    packet.mixer_group = mixer_group;
    packet.mixer_sub_index = mixer_sub_index;
    packet.mixer_type = mixer_type;
    packet.param_type = param_type;
    packet.param_array_size = param_array_size;
    mav_array_memcpy(packet.param_values, param_values, sizeof(float)*8);
    mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MIXER_PARAMETER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MIXER_PARAMETER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MIXER_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_MIXER_PARAMETER_LEN, MAVLINK_MSG_ID_MIXER_PARAMETER_CRC);
}

/**
 * @brief Encode a mixer_parameter struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mixer_parameter C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mixer_parameter_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mixer_parameter_t* mixer_parameter)
{
    return mavlink_msg_mixer_parameter_pack(system_id, component_id, msg, mixer_parameter->count, mixer_parameter->index, mixer_parameter->mixer_group, mixer_parameter->mixer_index, mixer_parameter->mixer_sub_index, mixer_parameter->mixer_type, mixer_parameter->parameter_index, mixer_parameter->param_type, mixer_parameter->param_array_size, mixer_parameter->param_id, mixer_parameter->param_values);
}

/**
 * @brief Encode a mixer_parameter struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mixer_parameter C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mixer_parameter_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mixer_parameter_t* mixer_parameter)
{
    return mavlink_msg_mixer_parameter_pack_chan(system_id, component_id, chan, msg, mixer_parameter->count, mixer_parameter->index, mixer_parameter->mixer_group, mixer_parameter->mixer_index, mixer_parameter->mixer_sub_index, mixer_parameter->mixer_type, mixer_parameter->parameter_index, mixer_parameter->param_type, mixer_parameter->param_array_size, mixer_parameter->param_id, mixer_parameter->param_values);
}

/**
 * @brief Send a mixer_parameter message
 * @param chan MAVLink channel to send the message
 *
 * @param count Total number of onboard parameters
 * @param index Index of this onboard parameter
 * @param mixer_group Access to different sets of mixers
 * @param mixer_index Index of the mixer in the group
 * @param mixer_sub_index Index of the sub mixer in the mixer
 * @param mixer_type Implementation specific identifier for mixer type
 * @param parameter_index Index of the parameter in a mixer or something else
 * @param param_type Parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 * @param param_array_size Size of the array for this parameter
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_values Array of parameter values
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mixer_parameter_send(mavlink_channel_t chan, uint16_t count, uint16_t index, uint8_t mixer_group, uint16_t mixer_index, uint8_t mixer_sub_index, uint8_t mixer_type, uint16_t parameter_index, uint8_t param_type, uint8_t param_array_size, const char *param_id, const float *param_values)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_PARAMETER_LEN];
    _mav_put_uint16_t(buf, 32, count);
    _mav_put_uint16_t(buf, 34, index);
    _mav_put_uint16_t(buf, 36, mixer_index);
    _mav_put_uint16_t(buf, 38, parameter_index);
    _mav_put_uint8_t(buf, 40, mixer_group);
    _mav_put_uint8_t(buf, 41, mixer_sub_index);
    _mav_put_uint8_t(buf, 42, mixer_type);
    _mav_put_uint8_t(buf, 43, param_type);
    _mav_put_uint8_t(buf, 44, param_array_size);
    _mav_put_float_array(buf, 0, param_values, 8);
    _mav_put_char_array(buf, 45, param_id, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_PARAMETER, buf, MAVLINK_MSG_ID_MIXER_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_MIXER_PARAMETER_LEN, MAVLINK_MSG_ID_MIXER_PARAMETER_CRC);
#else
    mavlink_mixer_parameter_t packet;
    packet.count = count;
    packet.index = index;
    packet.mixer_index = mixer_index;
    packet.parameter_index = parameter_index;
    packet.mixer_group = mixer_group;
    packet.mixer_sub_index = mixer_sub_index;
    packet.mixer_type = mixer_type;
    packet.param_type = param_type;
    packet.param_array_size = param_array_size;
    mav_array_memcpy(packet.param_values, param_values, sizeof(float)*8);
    mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_PARAMETER, (const char *)&packet, MAVLINK_MSG_ID_MIXER_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_MIXER_PARAMETER_LEN, MAVLINK_MSG_ID_MIXER_PARAMETER_CRC);
#endif
}

/**
 * @brief Send a mixer_parameter message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mixer_parameter_send_struct(mavlink_channel_t chan, const mavlink_mixer_parameter_t* mixer_parameter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mixer_parameter_send(chan, mixer_parameter->count, mixer_parameter->index, mixer_parameter->mixer_group, mixer_parameter->mixer_index, mixer_parameter->mixer_sub_index, mixer_parameter->mixer_type, mixer_parameter->parameter_index, mixer_parameter->param_type, mixer_parameter->param_array_size, mixer_parameter->param_id, mixer_parameter->param_values);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_PARAMETER, (const char *)mixer_parameter, MAVLINK_MSG_ID_MIXER_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_MIXER_PARAMETER_LEN, MAVLINK_MSG_ID_MIXER_PARAMETER_CRC);
#endif
}

#if MAVLINK_MSG_ID_MIXER_PARAMETER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mixer_parameter_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t count, uint16_t index, uint8_t mixer_group, uint16_t mixer_index, uint8_t mixer_sub_index, uint8_t mixer_type, uint16_t parameter_index, uint8_t param_type, uint8_t param_array_size, const char *param_id, const float *param_values)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 32, count);
    _mav_put_uint16_t(buf, 34, index);
    _mav_put_uint16_t(buf, 36, mixer_index);
    _mav_put_uint16_t(buf, 38, parameter_index);
    _mav_put_uint8_t(buf, 40, mixer_group);
    _mav_put_uint8_t(buf, 41, mixer_sub_index);
    _mav_put_uint8_t(buf, 42, mixer_type);
    _mav_put_uint8_t(buf, 43, param_type);
    _mav_put_uint8_t(buf, 44, param_array_size);
    _mav_put_float_array(buf, 0, param_values, 8);
    _mav_put_char_array(buf, 45, param_id, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_PARAMETER, buf, MAVLINK_MSG_ID_MIXER_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_MIXER_PARAMETER_LEN, MAVLINK_MSG_ID_MIXER_PARAMETER_CRC);
#else
    mavlink_mixer_parameter_t *packet = (mavlink_mixer_parameter_t *)msgbuf;
    packet->count = count;
    packet->index = index;
    packet->mixer_index = mixer_index;
    packet->parameter_index = parameter_index;
    packet->mixer_group = mixer_group;
    packet->mixer_sub_index = mixer_sub_index;
    packet->mixer_type = mixer_type;
    packet->param_type = param_type;
    packet->param_array_size = param_array_size;
    mav_array_memcpy(packet->param_values, param_values, sizeof(float)*8);
    mav_array_memcpy(packet->param_id, param_id, sizeof(char)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_PARAMETER, (const char *)packet, MAVLINK_MSG_ID_MIXER_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_MIXER_PARAMETER_LEN, MAVLINK_MSG_ID_MIXER_PARAMETER_CRC);
#endif
}
#endif

#endif

// MESSAGE MIXER_PARAMETER UNPACKING


/**
 * @brief Get field count from mixer_parameter message
 *
 * @return Total number of onboard parameters
 */
static inline uint16_t mavlink_msg_mixer_parameter_get_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field index from mixer_parameter message
 *
 * @return Index of this onboard parameter
 */
static inline uint16_t mavlink_msg_mixer_parameter_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field mixer_group from mixer_parameter message
 *
 * @return Access to different sets of mixers
 */
static inline uint8_t mavlink_msg_mixer_parameter_get_mixer_group(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Get field mixer_index from mixer_parameter message
 *
 * @return Index of the mixer in the group
 */
static inline uint16_t mavlink_msg_mixer_parameter_get_mixer_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  36);
}

/**
 * @brief Get field mixer_sub_index from mixer_parameter message
 *
 * @return Index of the sub mixer in the mixer
 */
static inline uint8_t mavlink_msg_mixer_parameter_get_mixer_sub_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  41);
}

/**
 * @brief Get field mixer_type from mixer_parameter message
 *
 * @return Implementation specific identifier for mixer type
 */
static inline uint8_t mavlink_msg_mixer_parameter_get_mixer_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  42);
}

/**
 * @brief Get field parameter_index from mixer_parameter message
 *
 * @return Index of the parameter in a mixer or something else
 */
static inline uint16_t mavlink_msg_mixer_parameter_get_parameter_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  38);
}

/**
 * @brief Get field param_type from mixer_parameter message
 *
 * @return Parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 */
static inline uint8_t mavlink_msg_mixer_parameter_get_param_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  43);
}

/**
 * @brief Get field param_array_size from mixer_parameter message
 *
 * @return Size of the array for this parameter
 */
static inline uint8_t mavlink_msg_mixer_parameter_get_param_array_size(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  44);
}

/**
 * @brief Get field param_id from mixer_parameter message
 *
 * @return Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 */
static inline uint16_t mavlink_msg_mixer_parameter_get_param_id(const mavlink_message_t* msg, char *param_id)
{
    return _MAV_RETURN_char_array(msg, param_id, 16,  45);
}

/**
 * @brief Get field param_values from mixer_parameter message
 *
 * @return Array of parameter values
 */
static inline uint16_t mavlink_msg_mixer_parameter_get_param_values(const mavlink_message_t* msg, float *param_values)
{
    return _MAV_RETURN_float_array(msg, param_values, 8,  0);
}

/**
 * @brief Decode a mixer_parameter message into a struct
 *
 * @param msg The message to decode
 * @param mixer_parameter C-struct to decode the message contents into
 */
static inline void mavlink_msg_mixer_parameter_decode(const mavlink_message_t* msg, mavlink_mixer_parameter_t* mixer_parameter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mixer_parameter_get_param_values(msg, mixer_parameter->param_values);
    mixer_parameter->count = mavlink_msg_mixer_parameter_get_count(msg);
    mixer_parameter->index = mavlink_msg_mixer_parameter_get_index(msg);
    mixer_parameter->mixer_index = mavlink_msg_mixer_parameter_get_mixer_index(msg);
    mixer_parameter->parameter_index = mavlink_msg_mixer_parameter_get_parameter_index(msg);
    mixer_parameter->mixer_group = mavlink_msg_mixer_parameter_get_mixer_group(msg);
    mixer_parameter->mixer_sub_index = mavlink_msg_mixer_parameter_get_mixer_sub_index(msg);
    mixer_parameter->mixer_type = mavlink_msg_mixer_parameter_get_mixer_type(msg);
    mixer_parameter->param_type = mavlink_msg_mixer_parameter_get_param_type(msg);
    mixer_parameter->param_array_size = mavlink_msg_mixer_parameter_get_param_array_size(msg);
    mavlink_msg_mixer_parameter_get_param_id(msg, mixer_parameter->param_id);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MIXER_PARAMETER_LEN? msg->len : MAVLINK_MSG_ID_MIXER_PARAMETER_LEN;
        memset(mixer_parameter, 0, MAVLINK_MSG_ID_MIXER_PARAMETER_LEN);
    memcpy(mixer_parameter, _MAV_PAYLOAD(msg), len);
#endif
}
