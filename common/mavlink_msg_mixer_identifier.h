#pragma once
// MESSAGE MIXER_IDENTIFIER PACKING

#define MAVLINK_MSG_ID_MIXER_IDENTIFIER 237

MAVPACKED(
typedef struct __mavlink_mixer_identifier_t {
 uint16_t connection_index; /*< Index of the sub mixer in the mixer*/
 uint8_t data_type; /*< Mixer data type*/
 uint8_t type_index; /*< Index of the mixer in the group*/
 uint8_t parameter_index; /*< Index of the sub mixer in the mixer*/
 char identifier[32]; /*< identifier*/
}) mavlink_mixer_identifier_t;

#define MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN 37
#define MAVLINK_MSG_ID_MIXER_IDENTIFIER_MIN_LEN 37
#define MAVLINK_MSG_ID_237_LEN 37
#define MAVLINK_MSG_ID_237_MIN_LEN 37

#define MAVLINK_MSG_ID_MIXER_IDENTIFIER_CRC 231
#define MAVLINK_MSG_ID_237_CRC 231

#define MAVLINK_MSG_MIXER_IDENTIFIER_FIELD_IDENTIFIER_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MIXER_IDENTIFIER { \
    237, \
    "MIXER_IDENTIFIER", \
    5, \
    {  { "connection_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mixer_identifier_t, connection_index) }, \
         { "data_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mixer_identifier_t, data_type) }, \
         { "type_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mixer_identifier_t, type_index) }, \
         { "parameter_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mixer_identifier_t, parameter_index) }, \
         { "identifier", NULL, MAVLINK_TYPE_CHAR, 32, 5, offsetof(mavlink_mixer_identifier_t, identifier) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MIXER_IDENTIFIER { \
    "MIXER_IDENTIFIER", \
    5, \
    {  { "connection_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mixer_identifier_t, connection_index) }, \
         { "data_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mixer_identifier_t, data_type) }, \
         { "type_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mixer_identifier_t, type_index) }, \
         { "parameter_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mixer_identifier_t, parameter_index) }, \
         { "identifier", NULL, MAVLINK_TYPE_CHAR, 32, 5, offsetof(mavlink_mixer_identifier_t, identifier) }, \
         } \
}
#endif

/**
 * @brief Pack a mixer_identifier message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param data_type Mixer data type
 * @param type_index Index of the mixer in the group
 * @param parameter_index Index of the sub mixer in the mixer
 * @param connection_index Index of the sub mixer in the mixer
 * @param identifier identifier
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mixer_identifier_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t data_type, uint8_t type_index, uint8_t parameter_index, uint16_t connection_index, const char *identifier)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN];
    _mav_put_uint16_t(buf, 0, connection_index);
    _mav_put_uint8_t(buf, 2, data_type);
    _mav_put_uint8_t(buf, 3, type_index);
    _mav_put_uint8_t(buf, 4, parameter_index);
    _mav_put_char_array(buf, 5, identifier, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN);
#else
    mavlink_mixer_identifier_t packet;
    packet.connection_index = connection_index;
    packet.data_type = data_type;
    packet.type_index = type_index;
    packet.parameter_index = parameter_index;
    mav_array_memcpy(packet.identifier, identifier, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MIXER_IDENTIFIER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MIXER_IDENTIFIER_MIN_LEN, MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN, MAVLINK_MSG_ID_MIXER_IDENTIFIER_CRC);
}

/**
 * @brief Pack a mixer_identifier message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param data_type Mixer data type
 * @param type_index Index of the mixer in the group
 * @param parameter_index Index of the sub mixer in the mixer
 * @param connection_index Index of the sub mixer in the mixer
 * @param identifier identifier
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mixer_identifier_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t data_type,uint8_t type_index,uint8_t parameter_index,uint16_t connection_index,const char *identifier)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN];
    _mav_put_uint16_t(buf, 0, connection_index);
    _mav_put_uint8_t(buf, 2, data_type);
    _mav_put_uint8_t(buf, 3, type_index);
    _mav_put_uint8_t(buf, 4, parameter_index);
    _mav_put_char_array(buf, 5, identifier, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN);
#else
    mavlink_mixer_identifier_t packet;
    packet.connection_index = connection_index;
    packet.data_type = data_type;
    packet.type_index = type_index;
    packet.parameter_index = parameter_index;
    mav_array_memcpy(packet.identifier, identifier, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MIXER_IDENTIFIER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MIXER_IDENTIFIER_MIN_LEN, MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN, MAVLINK_MSG_ID_MIXER_IDENTIFIER_CRC);
}

/**
 * @brief Encode a mixer_identifier struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mixer_identifier C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mixer_identifier_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mixer_identifier_t* mixer_identifier)
{
    return mavlink_msg_mixer_identifier_pack(system_id, component_id, msg, mixer_identifier->data_type, mixer_identifier->type_index, mixer_identifier->parameter_index, mixer_identifier->connection_index, mixer_identifier->identifier);
}

/**
 * @brief Encode a mixer_identifier struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mixer_identifier C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mixer_identifier_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mixer_identifier_t* mixer_identifier)
{
    return mavlink_msg_mixer_identifier_pack_chan(system_id, component_id, chan, msg, mixer_identifier->data_type, mixer_identifier->type_index, mixer_identifier->parameter_index, mixer_identifier->connection_index, mixer_identifier->identifier);
}

/**
 * @brief Send a mixer_identifier message
 * @param chan MAVLink channel to send the message
 *
 * @param data_type Mixer data type
 * @param type_index Index of the mixer in the group
 * @param parameter_index Index of the sub mixer in the mixer
 * @param connection_index Index of the sub mixer in the mixer
 * @param identifier identifier
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mixer_identifier_send(mavlink_channel_t chan, uint8_t data_type, uint8_t type_index, uint8_t parameter_index, uint16_t connection_index, const char *identifier)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN];
    _mav_put_uint16_t(buf, 0, connection_index);
    _mav_put_uint8_t(buf, 2, data_type);
    _mav_put_uint8_t(buf, 3, type_index);
    _mav_put_uint8_t(buf, 4, parameter_index);
    _mav_put_char_array(buf, 5, identifier, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_IDENTIFIER, buf, MAVLINK_MSG_ID_MIXER_IDENTIFIER_MIN_LEN, MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN, MAVLINK_MSG_ID_MIXER_IDENTIFIER_CRC);
#else
    mavlink_mixer_identifier_t packet;
    packet.connection_index = connection_index;
    packet.data_type = data_type;
    packet.type_index = type_index;
    packet.parameter_index = parameter_index;
    mav_array_memcpy(packet.identifier, identifier, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_IDENTIFIER, (const char *)&packet, MAVLINK_MSG_ID_MIXER_IDENTIFIER_MIN_LEN, MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN, MAVLINK_MSG_ID_MIXER_IDENTIFIER_CRC);
#endif
}

/**
 * @brief Send a mixer_identifier message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mixer_identifier_send_struct(mavlink_channel_t chan, const mavlink_mixer_identifier_t* mixer_identifier)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mixer_identifier_send(chan, mixer_identifier->data_type, mixer_identifier->type_index, mixer_identifier->parameter_index, mixer_identifier->connection_index, mixer_identifier->identifier);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_IDENTIFIER, (const char *)mixer_identifier, MAVLINK_MSG_ID_MIXER_IDENTIFIER_MIN_LEN, MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN, MAVLINK_MSG_ID_MIXER_IDENTIFIER_CRC);
#endif
}

#if MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mixer_identifier_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t data_type, uint8_t type_index, uint8_t parameter_index, uint16_t connection_index, const char *identifier)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, connection_index);
    _mav_put_uint8_t(buf, 2, data_type);
    _mav_put_uint8_t(buf, 3, type_index);
    _mav_put_uint8_t(buf, 4, parameter_index);
    _mav_put_char_array(buf, 5, identifier, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_IDENTIFIER, buf, MAVLINK_MSG_ID_MIXER_IDENTIFIER_MIN_LEN, MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN, MAVLINK_MSG_ID_MIXER_IDENTIFIER_CRC);
#else
    mavlink_mixer_identifier_t *packet = (mavlink_mixer_identifier_t *)msgbuf;
    packet->connection_index = connection_index;
    packet->data_type = data_type;
    packet->type_index = type_index;
    packet->parameter_index = parameter_index;
    mav_array_memcpy(packet->identifier, identifier, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_IDENTIFIER, (const char *)packet, MAVLINK_MSG_ID_MIXER_IDENTIFIER_MIN_LEN, MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN, MAVLINK_MSG_ID_MIXER_IDENTIFIER_CRC);
#endif
}
#endif

#endif

// MESSAGE MIXER_IDENTIFIER UNPACKING


/**
 * @brief Get field data_type from mixer_identifier message
 *
 * @return Mixer data type
 */
static inline uint8_t mavlink_msg_mixer_identifier_get_data_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field type_index from mixer_identifier message
 *
 * @return Index of the mixer in the group
 */
static inline uint8_t mavlink_msg_mixer_identifier_get_type_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field parameter_index from mixer_identifier message
 *
 * @return Index of the sub mixer in the mixer
 */
static inline uint8_t mavlink_msg_mixer_identifier_get_parameter_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field connection_index from mixer_identifier message
 *
 * @return Index of the sub mixer in the mixer
 */
static inline uint16_t mavlink_msg_mixer_identifier_get_connection_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field identifier from mixer_identifier message
 *
 * @return identifier
 */
static inline uint16_t mavlink_msg_mixer_identifier_get_identifier(const mavlink_message_t* msg, char *identifier)
{
    return _MAV_RETURN_char_array(msg, identifier, 32,  5);
}

/**
 * @brief Decode a mixer_identifier message into a struct
 *
 * @param msg The message to decode
 * @param mixer_identifier C-struct to decode the message contents into
 */
static inline void mavlink_msg_mixer_identifier_decode(const mavlink_message_t* msg, mavlink_mixer_identifier_t* mixer_identifier)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mixer_identifier->connection_index = mavlink_msg_mixer_identifier_get_connection_index(msg);
    mixer_identifier->data_type = mavlink_msg_mixer_identifier_get_data_type(msg);
    mixer_identifier->type_index = mavlink_msg_mixer_identifier_get_type_index(msg);
    mixer_identifier->parameter_index = mavlink_msg_mixer_identifier_get_parameter_index(msg);
    mavlink_msg_mixer_identifier_get_identifier(msg, mixer_identifier->identifier);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN? msg->len : MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN;
        memset(mixer_identifier, 0, MAVLINK_MSG_ID_MIXER_IDENTIFIER_LEN);
    memcpy(mixer_identifier, _MAV_PAYLOAD(msg), len);
#endif
}
