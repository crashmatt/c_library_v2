#pragma once
// MESSAGE MIXER_CONNECTION PACKING

#define MAVLINK_MSG_ID_MIXER_CONNECTION 236

MAVPACKED(
typedef struct __mavlink_mixer_connection_t {
 int16_t conn_channel; /*< Connection channel in the group*/
 uint8_t mixer_group; /*< Access to different sets of mixers ie. onboard, failsafe, uavcan etc..*/
 uint8_t mixer_index; /*< Index of the mixer in the group*/
 uint8_t conn_type; /*< Type of the mixer connection*/
 uint8_t conn_index; /*< Index of the parameter in the mixer or sub mixer*/
 uint8_t conn_group; /*< Group of the mixer connection*/
}) mavlink_mixer_connection_t;

#define MAVLINK_MSG_ID_MIXER_CONNECTION_LEN 7
#define MAVLINK_MSG_ID_MIXER_CONNECTION_MIN_LEN 7
#define MAVLINK_MSG_ID_236_LEN 7
#define MAVLINK_MSG_ID_236_MIN_LEN 7

#define MAVLINK_MSG_ID_MIXER_CONNECTION_CRC 247
#define MAVLINK_MSG_ID_236_CRC 247



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MIXER_CONNECTION { \
    236, \
    "MIXER_CONNECTION", \
    6, \
    {  { "conn_channel", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_mixer_connection_t, conn_channel) }, \
         { "mixer_group", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mixer_connection_t, mixer_group) }, \
         { "mixer_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mixer_connection_t, mixer_index) }, \
         { "conn_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mixer_connection_t, conn_type) }, \
         { "conn_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_mixer_connection_t, conn_index) }, \
         { "conn_group", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_mixer_connection_t, conn_group) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MIXER_CONNECTION { \
    "MIXER_CONNECTION", \
    6, \
    {  { "conn_channel", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_mixer_connection_t, conn_channel) }, \
         { "mixer_group", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mixer_connection_t, mixer_group) }, \
         { "mixer_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mixer_connection_t, mixer_index) }, \
         { "conn_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mixer_connection_t, conn_type) }, \
         { "conn_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_mixer_connection_t, conn_index) }, \
         { "conn_group", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_mixer_connection_t, conn_group) }, \
         } \
}
#endif

/**
 * @brief Pack a mixer_connection message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mixer_group Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 * @param mixer_index Index of the mixer in the group
 * @param conn_type Type of the mixer connection
 * @param conn_index Index of the parameter in the mixer or sub mixer
 * @param conn_group Group of the mixer connection
 * @param conn_channel Connection channel in the group
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mixer_connection_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t mixer_group, uint8_t mixer_index, uint8_t conn_type, uint8_t conn_index, uint8_t conn_group, int16_t conn_channel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_CONNECTION_LEN];
    _mav_put_int16_t(buf, 0, conn_channel);
    _mav_put_uint8_t(buf, 2, mixer_group);
    _mav_put_uint8_t(buf, 3, mixer_index);
    _mav_put_uint8_t(buf, 4, conn_type);
    _mav_put_uint8_t(buf, 5, conn_index);
    _mav_put_uint8_t(buf, 6, conn_group);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MIXER_CONNECTION_LEN);
#else
    mavlink_mixer_connection_t packet;
    packet.conn_channel = conn_channel;
    packet.mixer_group = mixer_group;
    packet.mixer_index = mixer_index;
    packet.conn_type = conn_type;
    packet.conn_index = conn_index;
    packet.conn_group = conn_group;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MIXER_CONNECTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MIXER_CONNECTION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MIXER_CONNECTION_MIN_LEN, MAVLINK_MSG_ID_MIXER_CONNECTION_LEN, MAVLINK_MSG_ID_MIXER_CONNECTION_CRC);
}

/**
 * @brief Pack a mixer_connection message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mixer_group Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 * @param mixer_index Index of the mixer in the group
 * @param conn_type Type of the mixer connection
 * @param conn_index Index of the parameter in the mixer or sub mixer
 * @param conn_group Group of the mixer connection
 * @param conn_channel Connection channel in the group
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mixer_connection_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t mixer_group,uint8_t mixer_index,uint8_t conn_type,uint8_t conn_index,uint8_t conn_group,int16_t conn_channel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_CONNECTION_LEN];
    _mav_put_int16_t(buf, 0, conn_channel);
    _mav_put_uint8_t(buf, 2, mixer_group);
    _mav_put_uint8_t(buf, 3, mixer_index);
    _mav_put_uint8_t(buf, 4, conn_type);
    _mav_put_uint8_t(buf, 5, conn_index);
    _mav_put_uint8_t(buf, 6, conn_group);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MIXER_CONNECTION_LEN);
#else
    mavlink_mixer_connection_t packet;
    packet.conn_channel = conn_channel;
    packet.mixer_group = mixer_group;
    packet.mixer_index = mixer_index;
    packet.conn_type = conn_type;
    packet.conn_index = conn_index;
    packet.conn_group = conn_group;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MIXER_CONNECTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MIXER_CONNECTION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MIXER_CONNECTION_MIN_LEN, MAVLINK_MSG_ID_MIXER_CONNECTION_LEN, MAVLINK_MSG_ID_MIXER_CONNECTION_CRC);
}

/**
 * @brief Encode a mixer_connection struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mixer_connection C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mixer_connection_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mixer_connection_t* mixer_connection)
{
    return mavlink_msg_mixer_connection_pack(system_id, component_id, msg, mixer_connection->mixer_group, mixer_connection->mixer_index, mixer_connection->conn_type, mixer_connection->conn_index, mixer_connection->conn_group, mixer_connection->conn_channel);
}

/**
 * @brief Encode a mixer_connection struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mixer_connection C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mixer_connection_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mixer_connection_t* mixer_connection)
{
    return mavlink_msg_mixer_connection_pack_chan(system_id, component_id, chan, msg, mixer_connection->mixer_group, mixer_connection->mixer_index, mixer_connection->conn_type, mixer_connection->conn_index, mixer_connection->conn_group, mixer_connection->conn_channel);
}

/**
 * @brief Send a mixer_connection message
 * @param chan MAVLink channel to send the message
 *
 * @param mixer_group Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 * @param mixer_index Index of the mixer in the group
 * @param conn_type Type of the mixer connection
 * @param conn_index Index of the parameter in the mixer or sub mixer
 * @param conn_group Group of the mixer connection
 * @param conn_channel Connection channel in the group
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mixer_connection_send(mavlink_channel_t chan, uint8_t mixer_group, uint8_t mixer_index, uint8_t conn_type, uint8_t conn_index, uint8_t conn_group, int16_t conn_channel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MIXER_CONNECTION_LEN];
    _mav_put_int16_t(buf, 0, conn_channel);
    _mav_put_uint8_t(buf, 2, mixer_group);
    _mav_put_uint8_t(buf, 3, mixer_index);
    _mav_put_uint8_t(buf, 4, conn_type);
    _mav_put_uint8_t(buf, 5, conn_index);
    _mav_put_uint8_t(buf, 6, conn_group);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_CONNECTION, buf, MAVLINK_MSG_ID_MIXER_CONNECTION_MIN_LEN, MAVLINK_MSG_ID_MIXER_CONNECTION_LEN, MAVLINK_MSG_ID_MIXER_CONNECTION_CRC);
#else
    mavlink_mixer_connection_t packet;
    packet.conn_channel = conn_channel;
    packet.mixer_group = mixer_group;
    packet.mixer_index = mixer_index;
    packet.conn_type = conn_type;
    packet.conn_index = conn_index;
    packet.conn_group = conn_group;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_CONNECTION, (const char *)&packet, MAVLINK_MSG_ID_MIXER_CONNECTION_MIN_LEN, MAVLINK_MSG_ID_MIXER_CONNECTION_LEN, MAVLINK_MSG_ID_MIXER_CONNECTION_CRC);
#endif
}

/**
 * @brief Send a mixer_connection message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mixer_connection_send_struct(mavlink_channel_t chan, const mavlink_mixer_connection_t* mixer_connection)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mixer_connection_send(chan, mixer_connection->mixer_group, mixer_connection->mixer_index, mixer_connection->conn_type, mixer_connection->conn_index, mixer_connection->conn_group, mixer_connection->conn_channel);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_CONNECTION, (const char *)mixer_connection, MAVLINK_MSG_ID_MIXER_CONNECTION_MIN_LEN, MAVLINK_MSG_ID_MIXER_CONNECTION_LEN, MAVLINK_MSG_ID_MIXER_CONNECTION_CRC);
#endif
}

#if MAVLINK_MSG_ID_MIXER_CONNECTION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mixer_connection_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t mixer_group, uint8_t mixer_index, uint8_t conn_type, uint8_t conn_index, uint8_t conn_group, int16_t conn_channel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, conn_channel);
    _mav_put_uint8_t(buf, 2, mixer_group);
    _mav_put_uint8_t(buf, 3, mixer_index);
    _mav_put_uint8_t(buf, 4, conn_type);
    _mav_put_uint8_t(buf, 5, conn_index);
    _mav_put_uint8_t(buf, 6, conn_group);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_CONNECTION, buf, MAVLINK_MSG_ID_MIXER_CONNECTION_MIN_LEN, MAVLINK_MSG_ID_MIXER_CONNECTION_LEN, MAVLINK_MSG_ID_MIXER_CONNECTION_CRC);
#else
    mavlink_mixer_connection_t *packet = (mavlink_mixer_connection_t *)msgbuf;
    packet->conn_channel = conn_channel;
    packet->mixer_group = mixer_group;
    packet->mixer_index = mixer_index;
    packet->conn_type = conn_type;
    packet->conn_index = conn_index;
    packet->conn_group = conn_group;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MIXER_CONNECTION, (const char *)packet, MAVLINK_MSG_ID_MIXER_CONNECTION_MIN_LEN, MAVLINK_MSG_ID_MIXER_CONNECTION_LEN, MAVLINK_MSG_ID_MIXER_CONNECTION_CRC);
#endif
}
#endif

#endif

// MESSAGE MIXER_CONNECTION UNPACKING


/**
 * @brief Get field mixer_group from mixer_connection message
 *
 * @return Access to different sets of mixers ie. onboard, failsafe, uavcan etc..
 */
static inline uint8_t mavlink_msg_mixer_connection_get_mixer_group(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field mixer_index from mixer_connection message
 *
 * @return Index of the mixer in the group
 */
static inline uint8_t mavlink_msg_mixer_connection_get_mixer_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field conn_type from mixer_connection message
 *
 * @return Type of the mixer connection
 */
static inline uint8_t mavlink_msg_mixer_connection_get_conn_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field conn_index from mixer_connection message
 *
 * @return Index of the parameter in the mixer or sub mixer
 */
static inline uint8_t mavlink_msg_mixer_connection_get_conn_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field conn_group from mixer_connection message
 *
 * @return Group of the mixer connection
 */
static inline uint8_t mavlink_msg_mixer_connection_get_conn_group(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field conn_channel from mixer_connection message
 *
 * @return Connection channel in the group
 */
static inline int16_t mavlink_msg_mixer_connection_get_conn_channel(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Decode a mixer_connection message into a struct
 *
 * @param msg The message to decode
 * @param mixer_connection C-struct to decode the message contents into
 */
static inline void mavlink_msg_mixer_connection_decode(const mavlink_message_t* msg, mavlink_mixer_connection_t* mixer_connection)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mixer_connection->conn_channel = mavlink_msg_mixer_connection_get_conn_channel(msg);
    mixer_connection->mixer_group = mavlink_msg_mixer_connection_get_mixer_group(msg);
    mixer_connection->mixer_index = mavlink_msg_mixer_connection_get_mixer_index(msg);
    mixer_connection->conn_type = mavlink_msg_mixer_connection_get_conn_type(msg);
    mixer_connection->conn_index = mavlink_msg_mixer_connection_get_conn_index(msg);
    mixer_connection->conn_group = mavlink_msg_mixer_connection_get_conn_group(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MIXER_CONNECTION_LEN? msg->len : MAVLINK_MSG_ID_MIXER_CONNECTION_LEN;
        memset(mixer_connection, 0, MAVLINK_MSG_ID_MIXER_CONNECTION_LEN);
    memcpy(mixer_connection, _MAV_PAYLOAD(msg), len);
#endif
}
